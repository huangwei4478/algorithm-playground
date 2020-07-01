//
//  main.cpp
//  SolveSoduku
//
//  Created by huangwei on 2020/6/17.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        canSolveSudoku(0, 0, board);
    }
private:
    bool canSolveSudoku(int row, int col, vector<vector<char>>& board) {
        // base case: have we reach our goal?
        if (col == board[row].size()) {
            col = 0;
            row += 1;
            
            if (row == board.size()) {
                // problem solved
                return true;
            }
        }
        
        // Skip entires already filled out. They already have a value in them
        if (board[row][col] != '.') {
            return canSolveSudoku(row, col + 1, board);
        }
        
        // make decision
        for (int value = 1; value <= board.size(); value++) {
            char charToPlace = (char)(value + '0');
            
            if (canPlaceValue(board, row, col, charToPlace)) {
                board[row][col] = charToPlace;
                if (canSolveSudoku(row, col + 1, board)) {
                    return true;
                }
                board[row][col] = '.';
            }
        }
        
        // no decision to make, return false
        return false;
    }
    
    bool canPlaceValue(const vector<vector<char>>& board, int row, int col, char charToPlace) {
        // Check column of placement
        for (auto placementRow: board) {
            if (charToPlace == placementRow[col]) {
                return false;
            }
        }
        
        // Check row of placement
        for (int i = 0; i < board[row].size(); i++) {
            if (charToPlace == board[row][i]) {
                return false;
            }
        }
        
        // check region constraint - get the size of the sub-box
        int regionSize = (int)sqrt(board.size());
        
        int verticalBoxIndex = row / regionSize;
        int horizontalBoxIndex = col / regionSize;
        
        int topLeftOfSubBoxRow = regionSize * verticalBoxIndex;
        int topLeftOfSubBoxCol = regionSize * horizontalBoxIndex;
    
        // simple traverse this little box
        for (int i = 0; i < regionSize; i++) {
            for (int j = 0; j < regionSize; j++) {
                if (charToPlace == board[topLeftOfSubBoxRow + i][topLeftOfSubBoxCol + i]) {
                    return false;
                }
            }
        }
        return true;
    }
    
};

void printBoard(const vector<vector<char>>& board) {
    for ( const auto &row : board )
    {
       for ( const auto &s : row ) std::cout << s << ' ';
       std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<vector<char>> board
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    solution.solveSudoku(board);
    printBoard(board);
    return 0;
}
