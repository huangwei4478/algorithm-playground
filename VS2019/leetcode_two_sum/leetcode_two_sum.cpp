// leetcode_two_sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> map;

public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2) return nums;

        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (map.count(target - nums[i])) {
                return {nums[i], nums[map[target - nums[i]]]};
            }
        }

        return {};
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
