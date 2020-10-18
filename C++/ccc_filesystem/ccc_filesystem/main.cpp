//
//  main.cpp
//  ccc_filesystem
//
//  Created by huangwei on 2020/9/27.
//

#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <string>
#include <filesystem>

TEST_CASE("std::filesystem::path supports == and .empty()") {
    std::__fs::filesystem::path empty_path;
    std::__fs::filesystem::path shadow_path{ "/etc/shadow" };
    
    REQUIRE(empty_path.empty());
    REQUIRE(shadow_path == std::string{ "/etc/shadow" });
}
