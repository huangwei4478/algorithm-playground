//
//  main.cpp
//  05-linklist
//
//  Created by huangwei on 2022/4/14.
//

#include <iostream>
#include "LinkList.h"
#include "LinkListStack.h"
#include "ArrayStack.h"

double testStack(Stack<int> *stack, int opCount) {
    double startTime = clock();
    srand(777);
    
    for (int i = 0; i < opCount; i++) {
        stack -> push(rand());
    }
    
    for (int i = 0; i < opCount; i++) {
        stack -> pop();
    }
    
    double endTime = clock();
    
    return (endTime - startTime) / CLOCKS_PER_SEC;
}

int main(int argc, const char * argv[]) {
    int opCount = 1000000;
    
    ArrayStack<int> *arrayStack = new ArrayStack<int>{};
    LinkListStack<int> *linklistStack = new LinkListStack<int>{};
    
    std::cout << testStack(arrayStack, opCount) << " s for ArrayStack" << std::endl;
    std::cout << testStack(linklistStack, opCount) << " s for linkListStack" << std::endl;
    
    return 0;
}
