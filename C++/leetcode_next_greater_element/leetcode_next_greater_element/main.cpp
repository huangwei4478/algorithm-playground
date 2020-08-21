//
//  main.cpp
//  leetcode_next_greater_element
//
//  Created by huangwei on 2020/8/20.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(const vector<int>& nums) {
    size_t length = nums.size();
    if (length == 0) return {};
    
    vector<int> ans(length, 0);
    stack<int> monotonicDecreasingStack;
    
    for (size_t i = length - 1; i >= 0; --i) {
        while (!monotonicDecreasingStack.empty() && nums[i] >= monotonicDecreasingStack.top()) {
            monotonicDecreasingStack.pop();
        }
        ans[i] = monotonicDecreasingStack.empty() ? -1 : monotonicDecreasingStack.top();
        
        monotonicDecreasingStack.push(nums[i]);
    }
    return ans;
}

vector<int> dailyTemperatures(const vector<int>& T) {
    size_t length = T.size();
    vector<int> ans(length);
    stack<int> st;
    for (size_t i = length; i >= 0; --i) {
        while (!st.empty() && T[i] >= T[st.top()]) {
            st.pop();
        }
        
        ans[i] = st.empty() ? 0 : int(st.top() - i);           // 获得索引间距
        st.push(int(i));
    }
    return ans;
}

vector<int> nextGreaterElementsCircular(vector<int>& nums) {
    int n = int(nums.size());
    vector<int> res(n);
    stack<int> s;
    
    // Circular的其实也好做
    for (int i = 2 * n - 1; i >= 0; --i) {
        while (!s.empty() && nums[i % n] >= s.top()) {
            s.pop();
        }
        
        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
    
    return res;
}



int main(int argc, const char * argv[]) {
    
    vector<int> arr{ 2, 1, 2, 4, 3 };
    
    return 0;
}
