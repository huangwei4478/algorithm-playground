//
//  main.cpp
//  ccc_iterator
//
//  Created by huangwei on 2020/9/26.
//
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <deque>
#include <iterator>

TEST_CASE("std::back_inserter supports writing forward") {
    std::deque<int> dq;
    auto back_instr = std::back_inserter(dq);
    *back_instr = 2;
    ++back_instr;
    *back_instr = 4;
    ++back_instr;
    
    auto front_instr = std::front_inserter(dq);
    *front_instr = 1;
    ++front_instr;
    
    auto instr = std::inserter(dq, dq.begin() + 2);
    *instr = 3;
    instr++;
    
    REQUIRE(dq[0] == 1);
    REQUIRE(dq[1] == 2);
    REQUIRE(dq[2] == 3);
    REQUIRE(dq[3] == 4);
}
