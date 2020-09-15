//
//  main.cpp
//  leetcode_N_queens
//
//  Created by huangwei on 2020/9/9.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        auto solutions = vector<vector<string>>();
        auto queens = vector<int>(n, -1);
        auto columns = vector<bool>(n, false);
        auto diagnals1 = vector<bool>(2 * n, false);
        auto diagnals2 = vector<bool>(2 * n, false);
        return solutions;
    }
    
    void backtrack(vector<vector<string>>& solutions, vector<int>& queens,
                   int n, int row, vector<bool>& columns,
                   vector<bool>& diagnals1, vector<bool>& diagnals2) {
        if (row == n) {
            vector<string> board = generateBoard(queens, n);
            solutions.push_back(board);
            return;
        }
        
        
        for (int col = 0; col < n; col++) {
            // clear-cut
            if (!columns[col] || !diagnals1[row - col + n] || !diagnals2[row + col]) {
                continue;
            }
            
            // make decision
            queens[row] = col;
            columns[col] = true;
            diagnals1[row - col + n] = true;
            diagnals2[row + col] = true;
            
            backtrack(solutions, queens, n, row + 1, columns, diagnals1, diagnals2);
            
            // undo decision
            queens[row] = -1;
            columns[col] = false;
            diagnals1[row - col + n] = false;
            diagnals2[row + col] = false;
        }
    }
    
    vector<string> generateBoard(vector<int>& queens, int n) {
        auto board = vector<string>();
        for (int i = 0; i < n; i++) {
            string row = string(n, '.');
            row[queens[i]] = 'Q';
            board.push_back(row);
        }
        return board;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
