//
//  main.cpp
//  leetcode_MyCircularDeque
//
//  Created by huangwei on 2020/8/19.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int capacity;
public:
    MyCircularDeque(int k) {
        capacity = k + 1;
        arr.assign(capacity, 0);
        
        front = 0;
        rear = 0;
    }
    
    bool insertFront(int value) {
        
    }
    
    bool isEmpty() {
        return front == rear;
    }
    
    bool isFull() {
        return (rear + 1) % capacity == front;
    }
};
