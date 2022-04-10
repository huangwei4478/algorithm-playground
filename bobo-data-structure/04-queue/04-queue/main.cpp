//
//  main.cpp
//  04-queue
//
//  Created by huangwei on 2022/4/10.
//

#include <iostream>
#include "ArrayQueue.h"

int main(int argc, const char * argv[]) {
    ArrayQueue<int> *arrayQueue = new ArrayQueue<int>();
    for (int i = 0; i < 10; ++i) {
        arrayQueue->enqueue(i);
        arrayQueue->print();
        if (i % 3 == 2) {
            arrayQueue->dequeue();
            arrayQueue->print();
        }
    }
    arrayQueue = nullptr;
    delete arrayQueue;
    return 0;
    
}
