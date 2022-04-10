//
//  Array.hpp
//  02-custom-Array
//
//  Created by huangwei on 2022/4/5.
//

#ifndef Array_hpp
#define Array_hpp

#include <cassert>

class Array {
public:
    Array(int capacity) {
        data = new int[capacity];
        size = 0;
        this -> capacity = capacity;
    }
    
    Array(): Array(10) {}
    
    int getSize() {
        return size;
    }
    
    int getCapacity() {
        return capacity;
    }
    
    int isEmpty() {
        return size == 0;
    }
    
    int isFull() {
        return size == capacity;
    }
    
    void addLast(int e) {
        add(size, e);
    }
    
    void addFirst(int e) {
        add(0, e);
    }
    
    /// 在 index 的位置插入一个新元素 e
    void add(int index, int e) {
        assert(size < capacity);
        assert(index > 0 && index <= size);
        // move A[index, size) a slot backward
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        
        data[index] = e;
        size++;
    }
    
    
private:
    int *data;
    int size;       // A[0...size)
    int capacity;
};

#endif /* Array_hpp */
