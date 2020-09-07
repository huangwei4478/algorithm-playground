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


vector<int> nextGreaterElement(vector<int>& nums) {
    int length = int(nums.size());
    if (length == 0) return {};
    stack<int> monotonicDecreasingStack;
    vector<int> ans(length, 0);
    
    for (int i = length = 1; i >= 0; i--) {
        while (!monotonicDecreasingStack.empty() && nums[i] >= monotonicDecreasingStack.top()) {
            monotonicDecreasingStack.pop();
        }
        ans[i] = monotonicDecreasingStack.empty() ? -1 : monotonicDecreasingStack.top();
        monotonicDecreasingStack.push(nums[i]);
    }
    
    return ans;
}

vector<int> dailyTemperatures(vector<int>& T) {
    vector<int> ans(T.size());
    stack<int> st;
    
    for (int i = T.size() - 1; i >= 0; i--) {
        while (!st.empty() && T[st.top()] <= T[i]) {
            st.pop();
        }
        ans[i] = st.empty() ? 0 : (st.top() - i);
        st.push(i);
    }
    return ans;
}



int main(int argc, const char * argv[]) {
    
    vector<int> arr{ 2, 1, 2, 4, 3 };
    
    return 0;
}
