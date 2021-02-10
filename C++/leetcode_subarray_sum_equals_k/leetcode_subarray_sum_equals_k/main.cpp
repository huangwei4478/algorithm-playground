//
//  main.cpp
//  leetcode_subarray_sum_equals_k
//
//  Created by huangwei on 2021/2/9.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    // key: preSum, value: how many times does this preSum appears
    unordered_map<int, int> preSum;
    
public:
    int subarraySum(vector<int>& nums, int k) {
        if (nums.size() == 0) return 0;
        
        int ans = 0;
        
        int sum0_i = 0;
        preSum.insert({0, 1});
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            sum0_i += nums[i];
            
            int sum0_j = sum0_i - k;
            
            if (preSum.count(sum0_j) > 0) {
                ans += preSum[sum0_j];
            }
            
            if (preSum.count(sum0_i) > 0) {
                preSum[sum0_i] += 1;
            } else {
                preSum[sum0_i] = 1;
            }
        }
        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
