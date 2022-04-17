//
//  LinkListStack.h
//  05-linklist
//
//  Created by huangwei on 2022/4/17.
//

#ifndef LinkListStack_h
#define LinkListStack_h
#include "Stack.h"

template <typename T>
class LinkListStack: public Stack<T> {
public:
    LinkListStack<T>() {
        linkList = new LinkedList<T>();
    }
    
    int getSize() {
        return linkList -> getSize();
    }
    
    bool isEmpty() {
        return linkList -> isEmpty();
    }
    
    void push(T e) {
        linkList -> addFirst(e);
    }
    
    T pop() {
        return linkList -> removeFirst();
    }
    
    T peek() {
        return linkList -> getFirst();
    }
    
private:
    LinkedList<T> *linkList;
};

#endif /* LinkListStack_h */
