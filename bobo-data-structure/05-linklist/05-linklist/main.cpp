//
//  main.cpp
//  05-linklist
//
//  Created by huangwei on 2022/4/14.
//

#include <iostream>
#include "LinkList.h"


int main(int argc, const char * argv[]) {
    LinkedList<int> *linkedList = new LinkedList<int>();
    for (int i = 0; i < 5; i++) {
        linkedList -> addFirst(i);
        linkedList -> print();
    }
    
    linkedList -> add(2, 666);
    linkedList -> print();
    
    return 0;
}
