// leetcode_subset.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) return {};

        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }

private:
    vector<vector<int>> res;

    void backtrack(const vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);

        for (int i = start; i < nums.size(); i++) {
            track.push_back(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }
};

class Solution_subset2 {
private:
    vector<vector<int>> res;

    void backtrack(const vector<int>& nums, int start, vector<int>& track) {
        res.push_back(track);

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;

            track.push_back(nums[i]);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) return {};
        sort(nums.begin(), nums.end());
        vector<int> track;
        backtrack(nums, 0, track);
        return res;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
