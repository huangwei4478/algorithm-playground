//
//  ArrayQueue.h
//  04-queue
//
//  Created by huangwei on 2022/4/10.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h

#include "Array.h"
#include "Queue.h"

template <typename T>
class ArrayQueue: Queue<T> {
public:
    ArrayQueue(int capacity) {
        array = new Array<T>(capacity);
    }
    
    ArrayQueue(): ArrayQueue{10} {}
    
    virtual ~ArrayQueue() {
        delete array;
        array = nullptr;
    }
    
    int getSize() {
        return array -> getSize();
    }
    
    int getCapacity() {
        return array -> getCapacity();
    }
    
    void enqueue(T e) {
        array -> addLast(e);
    }
    
    T dequeue() {
        return array -> removeFirst();
    }
    
    T getFront() {
        return array -> getFirst();
    }
    
    bool isEmpty() {
        return array -> isEmpty();
    }
    
    /**
     * 打印数组的所有元素
     */
    void print() {
        std::cout << "ArrayQueue: size = " << array->getSize() << ", capacity = " << array->getCapacity() << std::endl;
        std::cout << "front ";
        array->print();
        std::cout << " tail" << std::endl;
    }
    
    
    
private:
    Array<T> *array;
};

#endif /* ArrayQueue_h */
