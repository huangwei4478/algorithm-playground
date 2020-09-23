//
//  main.cpp
//  leetcode_coinChange
//
//  Created by huangwei on 2020/9/15.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution_DP_Table {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        // base value
        dp[0] = 0;
        for (int i = 0; i < dp.size(); i++) {
            for (int coin: coins) {
                // 子问题无解，跳过
                if (i - coin < 0) continue;
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return (dp[amount] == amount + 1) ? -1 : dp[amount];
    }
};

class Solution_Memo {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, 0);
        return help(dp, amount, coins);
    }
private:
    int help(vector<int>& dp, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (dp[amount] != 0) return dp[amount];
        int res = amount + 1;
        
        for (auto coin: coins) {
            if (amount - coin < 0) continue;
            int subproblem = help(dp, amount - coin, coins);
            if (subproblem == -1) continue;
            res = min(res, 1 + subproblem);
        }
        dp[amount] = res == (amount + 1) ? -1 : res;
        return dp[amount];
    }
};


class Solution_DFS_Greedy_Pruning {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (coins.size() == 0) { return -1; }
        sort(coins.rbegin(), coins.rend());
        int ans = INT_MAX;
        coinChange(coins, 0, amount, 0, ans);
        return ans == INT_MAX ? -1 : ans;
    }

    void coinChange(const vector<int>& coins, int coinIndex, int amount, int coinCount, int& ans) {
        int largestCoin = coins[coinIndex];
        if (coinIndex == coins.size() - 1) {
            if (amount % largestCoin == 0) {
                ans = min(ans, coinCount + amount / largestCoin);
            }
            return;
        }

        // DFS
        for (int k = amount / largestCoin; k >= 0 && coinCount + k < ans; k--) {
            coinChange(coins, coinIndex + 1, amount - k * largestCoin, coinCount + k, ans);
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution_DFS_Greedy_Pruning solution;
    vector<int> coins{2};
    std::cout << solution.coinChange(coins, 3) << std::endl;
    
    return 0;
}
