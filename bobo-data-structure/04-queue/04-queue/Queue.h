//
//  Queue.h
//  04-queue
//
//  Created by huangwei on 2022/4/10.
//

#ifndef Queue_h
#define Queue_h

template <typename T>
class Queue {
public:
    virtual int getSize() = 0;
    
    virtual bool isEmpty() = 0;
    
    virtual void enqueue(T e) = 0;
    
    virtual T dequeue() = 0;
    
    virtual T getFront() = 0;
};

#endif /* Queue_h */
