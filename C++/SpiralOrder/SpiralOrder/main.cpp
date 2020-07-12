//
//  main.cpp
//  SpiralOrder
//
//  Created by huangwei on 2020/7/11.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0, bottom = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;

        while (top < bottom && left < right) {
            for (int i = left; i < right; i++) { result.push_back(matrix[top][i]); }
            for (int i = top; i < bottom; i++) { result.push_back(matrix[i][right]); }
            for (int i = right; i > left; i--) { result.push_back(matrix[bottom][i]); }
            for (int i = bottom; i > top; i--) { result.push_back(matrix[i][left]); }

            // shrink into circle
            top++;
            bottom--;
            left++;
            right--;
        }

        // one row left
        if (top == bottom) {
            for (int i = left; i <= right; i++) { result.push_back(matrix[top][i]); }
        }
        // one column left
        else if (left == right) {
            for (int i = top; i <= bottom; i++) { result.push_back(matrix[i][left]); }
        }

        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> matrix{{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    Solution solution;
    auto result = solution.spiralOrder(matrix);
    for (auto num: result) {
        printf("%d ", num);
    }
    printf("\n");
    return 0;
}
