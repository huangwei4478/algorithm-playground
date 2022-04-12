//
//  main.cpp
//  04-queue
//
//  Created by huangwei on 2022/4/10.
//

#include <iostream>
#include "ArrayQueue.h"
#include "CircularQueue.h"

template <typename T>
double testQueue(T *queue, int opCount) {
    clock_t startTime = clock();
    srand(444);
    for (int i = 0; i < opCount; ++i) {
        queue -> enqueue(rand());
    }
    
    for (int i = 0; i < opCount; ++i) {
        queue -> dequeue();
    }
    
    clock_t endTime = clock();
    return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main(int argc, const char * argv[]) {
    CircularQueue<int> *circularQueue = new CircularQueue<int>();
    ArrayQueue<int> *arrayQueue = new ArrayQueue<int>();
    int opCount = 100000;
    
    double arrayQueueTime = testQueue(arrayQueue, opCount);
    double circularQueueTime = testQueue(circularQueue, opCount);
    
    std::cout << "ArrayQueue time: " << arrayQueueTime << " s" << std::endl;
    std::cout << "CircularQueue time: " << circularQueueTime << " s" << std::endl;
    std::cout << "ArrayQueueTime / CircularQueueTime: " << arrayQueueTime / circularQueueTime << std::endl;
    
    delete circularQueue;
    circularQueue = nullptr;
    
    delete arrayQueue;
    arrayQueue = nullptr;
    
    return 0;
    
}
