//
//  main.cpp
//  leetcode_monotonicStack
//
//  Created by huangwei on 2020/11/23.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums) {
    vector<int> res(nums.size());
    stack<int> s;
    
    for (int i = static_cast<int>(nums.size()) - 1; i >= 0; i--) {
        while (!s.empty() && nums[i] >= s.top()) {
            s.pop();
        }
        
        // nums[i] 身后的next great number
        res[i] = s.empty() ? -1 : s.top();
        s.push(nums[i]);
    }
    
    return res;
}

vector<int> dailyTemperature(vector<int>& T) {
    vector<int> res(T.size());
    stack<int> s;
    
    for (int i = T.size() - 1; i >= 0; i--) {
        while (!s.empty() && T[s.top()] <= T[i]) {
            s.pop();
        }
        
        res[i] = s.empty() ? 0 : (s.top() - i);
        s.push(i);
    }
    return res;
}

vector<int> nextGreaterElementsCircle(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    stack<int> s;
    
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!s.empty() && nums[i % n] >= s.top()) {
            s.pop();
        }
        res[i % n] = s.empty() ? -1 : s.top();
        s.push(nums[i % n]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
