//
//  main.cpp
//  leetcode_DP_intro
//
//  Created by huangwei on 2020/9/15.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int helper(vector<int>& memo, int n) {
    if (n == 1 || n == 2) return 1;
    if (memo[n] != 0) return memo[n];
    memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
    return memo[n];
}

int fib(int N) {
    if (N < 1) return 0;
    vector<int> memo(N + 1, 0);
    return helper(memo, N);
}


int fib_db(int N) {
    vector<int> dp(N + 1, 0);
    // base case
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
