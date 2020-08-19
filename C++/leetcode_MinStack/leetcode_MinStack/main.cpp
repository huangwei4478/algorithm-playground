//
//  main.cpp
//  leetcode_MinStack
//
//  Created by huangwei on 2020/8/18.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <stack>

class MinStack {
public:
    /** initialize your data structure here. */

    MinStack() {}
    
    void push(int x) {
        if (st.empty()) {
            st.push({ x, x });
        } else {
            auto pair = st.top();
            if (x > pair.second) {
                st.push({ x, pair.second });
            } else {
                st.push({ x, x });
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }

private:
    std::stack<std::pair<int, int>> st;
};

int main(int argc, const char * argv[]) {
    MinStack minst;
    minst.push(2);
    minst.push(0);
    minst.push(3);
    minst.push(0);
    
    /**
     ["MinStack","push","push","push","push","getMin","pop","getMin","pop","getMin","pop","getMin"]
     [[],[2],[0],[3],[0],[],[],[],[],[],[],[]]
     
     */
    
    std::cout << minst.getMin() << std::endl;
    minst.pop();
    std::cout << minst.getMin() << std::endl;
    minst.pop();
    std::cout << minst.getMin() << std::endl;
    minst.pop();
    std::cout << minst.getMin() << std::endl;

    return 0;
}
