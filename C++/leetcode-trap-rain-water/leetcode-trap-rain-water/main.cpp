//
//  main.cpp
//  leetcode-trap-rain-water
//
//  Created by huangwei on 2020/8/21.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() == 0) return 0;
    int length = int(height.size());
    int ans = 0;
    
    for (int i = 1; i < length - 1; i++) {
        int l_max = 0, r_max = 0;
        for (int j = i; j < length; j++) {
            r_max = max(r_max, height[j]);
        }
        
        for (int j = i; j >= 0; --j) {
            l_max = max(l_max, height[j]);
        }
        
        ans += min(l_max, r_max) - height[i];
    }
    
    return ans;
}

int trap_memo(vector<int>& height) {
    if (height.size() == 0) return 0;
    int length = int(height.size());
    
    vector<int> l_max(length), r_max(length);
    l_max[0] = height[0];
    r_max[length - 1] = height[length - 1];
    int ans = 0;
    
    for (int i = 1; i < length; i++) {
        l_max[i] = max(l_max[i - 1], height[i]);
    }
    
    for (int i = length - 2; i >= 0; i--) {
        r_max[i] = max(r_max[i + 1], height[i]);
    }
    
    for (int i = 1; i < length - 1; i++) {
        ans += min(l_max[i], r_max[i]) - height[i];
    }
    
    return ans;
}

int trap_double_pointer(vector<int>& height) {
    if (height.size() == 0) return 0;
    int length = int(height.size());
    int area = 0;
    
    int l_max = height[0], r_max = height[length - 1];
    int left = 0, right = length - 1;
    
    while (left <= right) {
        l_max = max(height[left], l_max);
        r_max = max(height[right], r_max);
        
        if (l_max < r_max) {
            area += l_max - height[left];
            left++;
        } else {
            area += r_max - height[right];
            right--;
        }
    }
    
    return area;
}

int trap_monotonic_decreasing_stack(vector<int>& height) {
    if (height.size() == 0) return 0;
    int length = int(height.size());
    int area = 0;
    
    stack<int> st;
    
    for (int i = 0; i < length; i++) {
        while (!st.empty() && height[st.top()] < height[i]) {
            int right_index = i;
            int curr_index = st.top();
            st.pop();
            if (st.empty()) break;
            int left_index = st.top();

            int width = right_index - left_index - 1;
            int h = min(height[left_index], height[right_index]) - height[curr_index];
            area += width * h;
        }
        st.push(i);
    }
    
    
    return area;;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
