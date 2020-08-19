//
//  main.cpp
//  leetcode_moveZeroes
//
//  Created by huangwei on 2020/8/12.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        size_t slowIndex = 0;
        size_t fastIndex = 0;
        size_t length = nums.size();
        for (; fastIndex < length; fastIndex++) {
            if (nums[fastIndex] != 0) {
                int temp = nums[fastIndex];
                nums[fastIndex] = nums[slowIndex];
                nums[slowIndex] = temp;
                slowIndex ++;
            }
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    std::vector<int> nums{0,1,0,3,12};
    solution.moveZeroes(nums);
    
    return 0;
}
