//
//  main.cpp
//  test_boost
//
//  Created by huangwei on 2020/9/23.
//

#define CATCH_CONFIG_MAIN
#include <boost/smart_ptr/scoped_ptr.hpp>
#include <catch2/catch.hpp>
#include <utility>

struct DeadMenOfDunharrow {
  DeadMenOfDunharrow(const char* m = "")
      : message{ m } {
    oaths_to_fulfill++;
  }
  ~DeadMenOfDunharrow() {
    oaths_to_fulfill--;
  }
  const char* message;
  static int oaths_to_fulfill;
};
int DeadMenOfDunharrow::oaths_to_fulfill{};
using ScopedOathbreakers = boost::scoped_ptr<DeadMenOfDunharrow>;

TEST_CASE("ScopedPtr evaluates to ") {
  SECTION("true when full") {
    ScopedOathbreakers aragorn{ new DeadMenOfDunharrow };
    REQUIRE(aragorn);
  }
  SECTION("false when empty") {
    ScopedOathbreakers aragorn;
    REQUIRE_FALSE(aragorn);
  }
}
