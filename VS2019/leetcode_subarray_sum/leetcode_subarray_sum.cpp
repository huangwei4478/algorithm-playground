// leetcode_subarray_sum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_map>
/**

给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。

示例 1 :

输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。

说明 :

    数组的长度为 [1, 20,000]。
    数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/subarray-sum-equals-k
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

*/

using namespace std;

// preSum[i] : sum of nums[0 .. i - 1]
// nums[i ... j] = preSum[j + 1] - preSum[i]

class Solution {
public:
   
int subarraySum(vector<int>& nums, int k) {
        int N = nums.size();

        // key: preSum; value: the count of that preSum
        unordered_map<int, int> preSum;
        
        preSum.insert({ 0, 1 });

        int ans = 0;
        int sum0_i = 0;

        for (int i = 0; i < N; i++) {
            sum0_i += nums[i];

            int sum0_j = sum0_i - k;

            if (preSum.count(sum0_j)) {
                ans += preSum[sum0_j];
            }

            if (preSum.count(sum0_i) > 0) {
                preSum[sum0_i]++;
            } else {
                preSum[sum0_i] = 1;
            }
        }
        
        return ans;
    }
};