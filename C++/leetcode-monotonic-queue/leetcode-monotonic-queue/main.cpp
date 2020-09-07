//
//  main.cpp
//  leetcode-monotonic-queue
//
//  Created by huangwei on 2020/8/21.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <deque>


class MonotonicQueue {
public:
    void enqueue(int n) {
        while (!data.empty() && n > data.back()) {
            data.pop_back();
        }
        data.push_back(n);
    }
    
    int max() {
        return data.front();
    }
    
    void dequeue(int n) {
        if (!data.empty() && data.front() == n) {
            data.pop_front();
        }
    }
private:
    std::deque<int> data;
};


int main(int argc, const char * argv[]) {
    
    return 0;
}
