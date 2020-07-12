//
//  main.cpp
//  ClimingStairs
//
//  Created by huangwei on 2020/7/11.
//  Copyright © 2020 huangwei. All rights reserved.
//

/**
 https://github.com/bephrem1/backtobackswe/blob/master/Dynamic%20Programming%2C%20Recursion%2C%20%26%20Backtracking/ClimbingStairs/TopDown.java
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo = vector<int>(n + 1, 0);
        return climbStairsHelper(n, memo);
    }
    
private:
    int climbStairsHelper(int n, vector<int>& memo) {
        /**
         0 distinct ways to climb negative steps if we
         can only take 1 or 2 steps
         */
        if (n < 0) { return 0; }
        
        /**
         1 distinct way to climb 1 if we can only take 1 or 2 steps.
         We take 1 step.
         */
        if (n == 0) { return 1; }
        
        /**
         Do we already have an answer to this question (subproblem) ?
         If not fall through and compute, BUT if we already know it
         just return it from the cache.
         */
        if (memo[n] > 0) { return memo[n]; }
        
        /**
         The answer to this subproblem is the sum of the answer to the
         subproblem  n - 1 and n - 2
         
         this drills us towards our base cases that bring us back up with an answer.
         
         We cache the answer before returning it so we have it later.
         */
        memo[n] = climbStairsHelper(n - 1, memo) + climbStairsHelper(n - 2, memo);
        
        return memo[n];
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    
    cout << solution.climbStairs(16) << endl;
    return 0;
}
