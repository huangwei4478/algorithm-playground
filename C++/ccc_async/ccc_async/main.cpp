//
//  main.cpp
//  ccc_async
//
//  Created by huangwei on 2020/9/28.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <future>
#include <string>

using namespace std;

TEST_CASE("async returns valid future") {
    using namespace literals::string_literals;
    
    auto the_future = async([]{ return "female"s; });
    REQUIRE(the_future.valid());
}

TEST_CASE("Future invalid by default") {
    future<bool> default_future;
    REQUIRE_FALSE(default_future.valid());
}

TEST_CASE("async returns the return value of the function objects") {
    using namespace literals::string_literals;
    auto the_future = async([] { return "female"s; });
    REQUIRE(the_future.get() == "future");
}

TEST_CASE("get may throw") {
    auto ghostrider = async([] { throw runtime_error{ "The pattern is full." }; });
    REQUIRE_THROWS_AS(ghostrider.get(), runtime_error);
}


TEST_CASE("wait for indicates whether a task is ready") {
    using namespace literals::chrono_literals;
    
    auto sleepy = async(launch::async, [] { this_thread::sleep_for(100ms); });
    const auto not_ready_yet = sleepy.wait_for(25ms);
    REQUIRE(not_ready_yet == future_status::timeout);
    const auto totally_ready = sleepy.wait_for(100ms);
    REQUIRE(totally_ready == future_status::ready);
}

#include <set>

template <typename T>
std::set<T> factorize(T x) {
    std::set<T> result{ 1 };
    for (T candidate{ 2 }; candidate <= x; candidate++) {
        if (x % candidate == 0) {
            result.insert(candidate);
            x /= candidate;
            candidate = 1;
        }
    }
    return result;
}
