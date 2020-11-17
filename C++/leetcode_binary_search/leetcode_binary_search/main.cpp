//
//  main.cpp
//  leetcode_binary_search
//
//  Created by huangwei on 2020/10/18.
//

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int left = 0, right = static_cast<int>(nums.size() - 1);
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1;
        }
    }
    
    return -1;
}

// 左侧边界，二分搜索, nums = [1, 2, 2, 2, 3], target = 2, return = 1
int left_bound(const vector<int>& nums, int target) {
    if (nums.size() == 0) {
        return -1;
    }
    
    int left = 0;
    int right = int(nums.size());
    
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            right = mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    
    return left;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
