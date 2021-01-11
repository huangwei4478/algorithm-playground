//
//  main.cpp
//  cpp_knapsack01
//
//  Created by huangwei on 2021/1/5.
//

#include <iostream>
#include <vector>

using namespace std;

class Knapsack01 {

private:
    
    // 因为约束的问题有 index，c，所以要用二维数组才搞得定缓存
    // N 行，每一行是 C + 1位
    // memo[index][c]: 用 [0 ... index] 的物品，填充容积为c的背包
    vector<vector<int>> memo;
    
    // 用 [0 ... index] 的物品，填充容积为c的背包，所产生的最大价值
    int bestValue(const vector<int> &w, const vector<int> &v, int index, int c) {
        if ( index < 0 || c <= 0 ) {
            return 0;
        }
        
        if ( memo[index][c] != -1 ) {
            return memo[index][c];
        }
        
        int res = bestValue(w, v, index - 1, c);
        if ( c >= w[index] ) {
            res = max(res, ( v[index] + bestValue(w, v, index - 1, c - w[index]) ));
        }
        
        memo[index][c] = res;
        
        return res;
    }
    
public:
    
    int knapsack01(const vector<int> &w, const vector<int> &v, int C) {
        if (w.size() != v.size()) return 0;
        if (w.size() == 0) return 0;
        int n = int(w.size());
        memo = vector<vector<int>>( n, vector<int>(C + 1, -1));
        return bestValue( w, v, n - 1, C);
    }
};

class Knapsack01_bottomUp {
    
    
public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int c) {
        assert( w.size() == v.size() );
        
        int n = int(w.size());
        if ( n == 0 ) return 0;
        vector<vector<int>> memo( n, vector<int>(c + 1, -1 ) );
        
        // 先搞定第一层，第一层是base case
        // 第一层，只能选择放 “一个”
        for (int j = 0; j <= c; j ++) {
            memo[0][j] = ( j >= 0 ? v[0] : 0 );
        }
        
        for ( int i = 1; i < n; i ++) {
            for ( int j = 0; j <= c; j ++ ) {
                int res = 0;
                res = memo[i - 1][j];
                if ( j >= w[i] ) {
                    res = max( res, (memo[i-1][j - w[i]] + v[i]) );
                }
                memo[i][j] = res;
            }
        }
        
        return memo[n - 1][c];
    }
};

class Knapsack01_bottomUp_refine_space {
public:
    int knapsack01(const vector<int> &w, const vector<int> &v, int c) {
        assert( w.size() == v.size() );
        
        int n = int(w.size());
        if ( n == 0 ) return 0;
        vector<int> memo(c + 1, -1 );
        
        for (int j = 0; j <= c; j ++) {
            memo[j] = ( j >= 0 ? v[0] : 0 );
        }
        
        for ( int i = 1; i < n; i ++) {
            for ( int j = c; j >= w[i]; j ++ ) {
                int res = 0;
                res = memo[j];
                if ( j >= w[i] ) {
                    res = max( res, (memo[j - w[i]] + v[i]));
                }
                memo[j] = res;
            }
        }
        
        return memo[c];
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
