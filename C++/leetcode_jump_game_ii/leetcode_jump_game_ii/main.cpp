//
//  main.cpp
//  leetcode_jump_game_ii
//
//  Created by huangwei on 2020/9/17.
//

#include <iostream>
#include <vector>

using namespace std;

int jump2(vector<int>& nums) {
    int maxPos = 0;
    int n = nums.size();
    int end = 0;
    int step = 0;
    for (int i = 0; i < n - 1; i++) {
        if (maxPos >= i) {
            maxPos = max(maxPos, i + nums[i]);
            if (i == end) {
                end = maxPos;
                ++step;
            }
        }
    }
    return step;
}

int jump(vector<int> &nums) {
    int ans = 0;
    int start = 0;
    int end = 1;
    
    while (end < nums.size()) {
        int maxPos = 0;
        for (int i = start; i < end; i++) {
            maxPos = max(maxPos, i + nums[i]);
        }
        start = end;
        end = maxPos + 1;
        ans++;
    }
    
    return ans;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
