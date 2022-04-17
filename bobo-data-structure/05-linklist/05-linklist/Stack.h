//
//  Stack.h
//  05-linklist
//
//  Created by huangwei on 2022/4/17.
//

#ifndef Stack_h
#define Stack_h

template <typename T>
class Stack {
public:
    virtual int getSize() = 0;
    virtual bool isEmpty() = 0;
    virtual void push(T e) = 0;
    virtual T pop() = 0;
    virtual T peek() = 0;
};


#endif /* Stack_h */
