//
//  main.cpp
//  02-custom-Array
//
//  Created by huangwei on 2022/4/5.
//

#include <iostream>
#include "Array.hpp"

int main(int argc, const char * argv[]) {
    Array<int> *array = new Array<int>(20);
    for (int i = 0; i < 10; ++i) {
        array->addLast(i);
    }
    array->print();
    array->add(1, 100);
    array->addFirst(-1);
    array->print();
    array->remove(2);
    array->print();
    array->removeElement(4);
    array->print();
    array->removeFirst();
    array->print();
    
    array = nullptr;
    delete array;
    return 0;
}
