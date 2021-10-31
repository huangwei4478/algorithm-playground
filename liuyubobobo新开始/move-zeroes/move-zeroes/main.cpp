//
//  main.cpp
//  move-zeroes
//
//  Created by huangwei on 2021/10/31.
//

#include <iostream>
#include <vector>

using namespace std;

class Solutions {
public:
	void moveZeroes_simple(vector<int>& nums) {
		vector<int> nonZeroElements;
		
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i]) {
				nonZeroElements.push_back( nums[i] );
			}
		}
		
		for (int i = 0; i < nonZeroElements.size(); i++) {
			nums[i] = nonZeroElements[i];
		}
		
		for (int i = nonZeroElements.size(); i < nums.size(); i++) {
			nums[i] = 0;
		}
	}
	
	/// [0 - k) 中保存当前遍历的非0元素
	void moveZeroes_no_extra_space(vector<int>& nums) {
		int k = 0;						// nums中，[0 ... k) 的元素均为非0元素
		
		// 遍历到第 i 个元素后，保证 [0 ... i] 中所有的非0元素
		// 都按照顺序排列在 [0 ... k) 中
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[k] = nums[i];
				k++;
			}
		}
		
		// 将nums剩余的位置，放置为0
		for (int i = k; i < nums.size(); i++) {
			nums[k] = 0;
		}
	}
	
	void moveZeroes(vector<int>& nums) {
		int k = 0;
		
		// 保证[0...i] 的所有的非0的元素
		// 都按照顺序排列在[0...k)中
		// 同时，顺便保证 [k...i] 为0
		
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				swap(nums[k], nums[i]);
				k++;
			}
		}
	}
};

int main(int argc, const char * argv[]) {
	// insert code here...
	std::cout << "Hello, World!\n";
	return 0;
}
