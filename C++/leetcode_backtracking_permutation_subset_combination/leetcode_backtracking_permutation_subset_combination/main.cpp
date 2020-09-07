//
//  main.cpp
//  leetcode_backtracking_permutation_subset_combination
//
//  Created by huangwei on 2020/9/4.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 数学归纳法
 */
vector<vector<int>> subsets01(vector<int>& nums) {
    // base case
    if (nums.empty()) return {{}};
    
    // take the last element
    int n = nums.back();
    nums.pop_back();
    
    vector<vector<int>> res = subsets01(nums);
    int size = int(res.size());
    for (int i = 0; i < size; i++) {
        res.push_back(res[i]);
        res.back().push_back(n);
    }
    
    return res;
}

//result = []
//def backtrack(path, list):
//    if condition satisfied:
//        result.add(path)
//        return
//    for choice in choices:
//        make_choice
//        backtrack(path, list)
//        undo_choice

class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 记录走过的路
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
    
    void backtrack(vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
