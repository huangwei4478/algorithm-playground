// leetcode_missing_number.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        sort(nums.begin(), nums.end());
        
        int N = nums.size();

        // check if it's in the end
        if (nums[N - 1] != N) return N;

        // check if it's in the beginning
        if (nums[0] != 0) return 0;

        for (int i = 1; i < N; i++) {
            int expectedNum = nums[i - 1] + 1;
             if (nums[i] != expectedNum) {
                return expectedNum;
            }
               
        }

        return -1;
    }
};

class Solution_hash_set {
private:
    unordered_set<int> set;

public:
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        
        for (int i = 0; i < nums.size(); i++) {
            set.insert(nums[i]);
        }

        for (int i = 0; i <= nums.size(); i++) {
            if (set.count(i) == 0) {
                return i;
            }
        }

        return -1;
    }
};


class Solution_xor {
    int missingNumber(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        
        int missing = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            missing ^= i ^ nums[i];
        }

        return missing;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}

