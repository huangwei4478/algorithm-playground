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
        rows = vector<bitset<9>>(9, bitset<9>());
        cols = vector<bitset<9>>(9, bitset<9>());
        cells = vector<vector<bitset<9>>>(3, vector<bitset<9>>(3, bitset<9>()));
        
        int cnt = 0;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                cnt += (board[i][j] == '.');
                if (board[i][j] == '.') continue;
                int n = board[i][j] - '1';
                rows[i] |= (1 << n);
                cols[j] |= (1 << n);
                cells[i / 3][j / 3] |= (1 << n);
            }
        }
        dfs(board, cnt);
    }
    
private:
    
    bool dfs(vector<vector<char>>& board, int cnt) {
        if (cnt == 0) { return true; }                  // Problem solved
        
        auto next = getNext(board);
        
        auto bits = getPossibleStatus(next[0], next[1]);
    
        if (bits.count() == 0) return false;
        
        for (int n = 0; n < bits.size(); n++) {
            if (!bits.test(n)) continue;
            // make decision
            fillNum(next[0], next[1], n, true);
            board[next[0]][next[1]] = n + '1';
            
            if (dfs(board, cnt - 1)) return true;
            
            // dfs failed, undo decision
            fillNum(next[0], next[1], n, false);
            board[next[0]][next[1]] = '.';
        }
        return false;
    }
    
    
    // 超出可能性最小的位置（包含已知信息最多的位置，这样的选择次数最少，贪心的思想
    vector<int> getNext(vector<vector<char>>& board) {
        vector<int> ret;
        size_t minCnt = 10;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[j].size(); j++) {
                if (board[i][j] != '.') continue;
                auto cur = getPossibleStatus(i, j);
                if (cur.count() >= minCnt) continue;
                ret = { i, j };
                minCnt = cur.count();
            }
        }
        return ret;
    }
    
    // 找出坐标 (i, j) 可以填入的数字
    bitset<9> getPossibleStatus(int x, int y) {
        return ~(rows[x] | cols[y] | cells[x / 3][y / 3]);
    }
    
    void fillNum(int x, int y, int n, bool fillFlag) {
        rows[x][n] = (fillFlag) ? (1) : (0);
        cols[y][n] = (fillFlag) ? (1) : (0);
        cells[x / 3][y / 3][n] = (fillFlag) ? (1) : (0);
    }
    
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
