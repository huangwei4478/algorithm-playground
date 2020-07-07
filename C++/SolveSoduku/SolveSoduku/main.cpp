//
//  main.cpp
//  SolveSoduku
//
//  Created by huangwei on 2020/6/17.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        rows = vector<bitset<9>>( 9, bitset<9>{ false } );
        cols = vector<bitset<9>>( 9, bitset<9>{ false } );
        cells = vector<vector<bitset<9>>>( 3, vector<bitset<9>>( 3, bitset<9>{ false } ) );
        
        int emptySlotCount = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == '.') emptySlotCount += 1;
                else {
                    // important! remember to setup rows, cols and cells data!
                    int n = board[i][j] - '1';
                    rows[i] |= 1 << n;
                    cols[j] |= 1 << n;
                    cells[i / 3][j / 3] = 1 << n;
                }
            }
        }
        
        dfs(board, emptySlotCount);
    }
    
    bool dfs(vector<vector<char>>& board, int emptySlotCount) {
        // Problem solved, all slot is fulled
        if (emptySlotCount == 0) return true;
        
        // Make decision:
        auto coord = getNextMinChoiceSlot(board);
        auto row = coord[0], col = coord[1];
        
        auto curStatus = getPossibleStatus(row, col, board);
        
        for (int i = 0; i < curStatus.size(); i++) {
            if (curStatus.test(i) == false) continue;            // skip the non-empty slot
            
            // try this number
            fillNum(row, col, i, true);
            board[row][col] = i + '1';
            
            if (dfs(board, emptySlotCount - 1)) return true;
            
            // undo changes
            fillNum(row, col, i, false);
            board[row][col] = '.';
        }
        
        return false;
    }
    
    // what is the possible status that (x, y) could be?
    bitset<9> getPossibleStatus(int x, int y, vector<vector<char>>& board) {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }
    
    vector<int> getNextMinChoiceSlot(vector<vector<char>>& board) {
        unsigned long curMinChoice = 10;
        vector<int> ret;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j, board);
                if (curMinChoice > cur.count()) {
                    ret = { i, j };
                    curMinChoice = cur.count();
                }
            }
        }
        return ret;
    }
    
    // record the data
    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = fillFlag ? true : false;
        cols[y][n] = fillFlag ? true : false;
        cells[x / 3][y / 3][n] = fillFlag ? true : false;
    }
    
private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> cells;
    
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
