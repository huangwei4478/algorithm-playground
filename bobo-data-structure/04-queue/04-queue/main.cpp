//
//  main.cpp
//  04-queue
//
//  Created by huangwei on 2022/4/10.
//

#include <iostream>
#include "ArrayQueue.h"
#include "CircularQueue.h"

int main(int argc, const char * argv[]) {
    CircularQueue<int> *circularQueue = new CircularQueue<int>();
    for (int i = 0; i < 10; ++i) {
        circularQueue->enqueue(i);
        circularQueue->print();
        if (i % 3 == 2) {
            circularQueue->dequeue();
            circularQueue->print();
        }
    }
    circularQueue = nullptr;
    delete circularQueue;
    return 0;
    
}
