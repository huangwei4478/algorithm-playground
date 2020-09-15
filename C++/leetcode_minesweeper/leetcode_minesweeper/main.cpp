//
//  main.cpp
//  leetcode_minesweeper
//
//  Created by huangwei on 2020/9/14.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    const int dir_x[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    const int dir_y[8] = {1, 0, -1, 0, 1, -1, 1, -1};
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        if (board.size() == 0 || board[0].size() == 0) { return {{}}; }
        int rows = board.size();
        int cols = board[0].size();
        int row = click[0], col = click[1];

        // rule 1
        if (board[row][col] == 'M') {
            board[row][col] = 'X';
        } else {
            dfs(board, row, col, rows, cols);
        }
        return board;
    }
    
    void dfs(vector<vector<char>>& board, int row, int col, int rows, int cols) {
        // 1. check the 'M' around the row and col (8 directions!)
        int mineCount = 0;
        for (int i = 0; i < 8; i++) {
            int tempRow = row + dir_x[i];
            int tempCol = col + dir_y[i];
            if (tempRow < 0 || tempRow >= rows || tempCol < 0 || tempCol >= cols) {
                continue;
            }
            if (board[tempRow][tempCol] == 'M') { mineCount++; }
        }

        // 2. if no mines, dfs in 8 directions, dig all 'E', mark itself as 'B'
        if (mineCount == 0) {
            board[row][col] = 'B';
            for (int i = 0; i < 8; i++) {
                int tempRow = row + dir_x[i];
                int tempCol = col + dir_y[i];
                if (tempRow < 0 || tempRow >= rows || tempCol < 0 || tempCol >= cols) {
                    continue;
                }
                if (board[tempRow][tempCol] != 'E') {
                    continue;
                }
                dfs(board, tempRow, tempCol, rows, cols);
            }
        } else {
            // 3. if there are mines, put a number to it and return
            board[row][col] = (mineCount + '0');
        }
    }
};

int main(int argc, const char * argv[]) {
    
    vector<vector<char>> board {
        {'E','E','E','E','E'},
        {'E','E','M','E','E'},
        {'E','E','E','E','E'},
        {'E','E','E','E','E'}
    };
    vector<int> click{ 3, 0 };
    
    Solution solution;
    
    auto newBoard = solution.updateBoard(board, click);
    for (auto row : newBoard) {
        for (auto letter: row) {
            std::cout << letter << ' ';
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}
