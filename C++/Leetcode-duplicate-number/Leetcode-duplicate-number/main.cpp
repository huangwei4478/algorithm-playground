//
//  main.cpp
//  Leetcode-duplicate-number
//
//  Created by huangwei on 2020/7/10.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        size_t length = nums.size();

        for (int i = 0; i < length; i++) {
            int index = abs(nums[i]);
            if (nums[index] <= 0 && i != 0) return abs(nums[i]) ;
            else { nums[index] *= -1; }
        }

        return -1;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Solution solution;
    vector<int> question{0, 1, 2, 3, 4, 11, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    
    cout << solution.findRepeatNumber(question) << endl;
    return 0;
}
