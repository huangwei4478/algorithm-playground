//
//  CircularQueue.h
//  04-queue
//
//  Created by huangwei on 2022/4/10.
//

#ifndef CircularQueue_h
#define CircularQueue_h

#include "Queue.h"

// Array[front ... tail)
// 容量 + 1
template <typename T>
class CircularQueue: Queue<T> {
public:
    CircularQueue(int capacity) {
        this -> capacity = capacity + 1;
        data = new T[capacity + 1];
        front = 0;
        tail = 0;
        size = 0;
    }
    
    CircularQueue(): CircularQueue(10) {}
    
    virtual ~CircularQueue() {
        delete [] data;
        data = nullptr;
    }
    
    int getCapacity() {
        return capacity - 1;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return front == tail;
    }
    
    void enqueue(T e) {
        if (isFull()) {
            resize(getCapacity() * 2);
        }
        
        data[tail] = e;
        tail = nextIndexOf(tail);
        size++;
    }
    
    T dequeue() {
        assert(!isEmpty());
        
        T ret = data[front];
        front = nextIndexOf(front);
        size--;
        
        if (size == getCapacity() / 4 && getCapacity() / 2 != 0) {
            resize(getCapacity() / 2);
        }
        
        return ret;
    }
    
    T getFront() {
        assert(!isEmpty());
        return data[front];
    }
    
    void print() {
        std::cout << "CircularQueue: size = " << getSize() << ", capacity = " << getCapacity() << std::endl;
        std::cout << "front [";
        for (int i = front; i != tail; i = nextIndexOf(i)) {
            std::cout << data[i];
            if (nextIndexOf(i) != tail) {
                std::cout << ", ";
            }
        }
        std::cout << "] tail" << std::endl;
    }
    
private:
    T* data;
    int front, tail;
    int size;
    int capacity;
    
    int nextIndexOf(int index) {
        return (index + 1) % capacity;
    }
    
    bool isFull() {
        return nextIndexOf(tail) == front;
    }
    
    void resize(int newCapacity) {
        T* newData = new T[newCapacity + 1];
        
        for (int i = 0; i < size; i++) {
            // 从 0 开始思考：有 front 的偏移
            newData[i] = data[(i + front) % capacity];
        }
        
        delete[] data;
        data = newData;
        
        front = 0;
        tail = size;
        capacity = newCapacity + 1;
    }
};


#endif /* CircularQueue_h */
