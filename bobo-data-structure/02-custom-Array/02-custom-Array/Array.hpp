//
//  Array.hpp
//  02-custom-Array
//
//  Created by huangwei on 2022/4/5.
//

#ifndef Array_hpp
#define Array_hpp

#include <cassert>
#include <iostream>

using namespace std;

template<typename T>
class Array {
public:
    Array(int capacity) {
        data = new T[capacity];
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
    
    void addLast(T e) {
        add(size, e);
    }
    
    void addFirst(T e) {
        add(0, e);
    }
    
    /// 在 index 的位置插入一个新元素 e
    void add(int index, T e) {
        assert(index >= 0 && index <= size);
        
        if (size == capacity) {
            resize(2 * capacity);
        }
        
        // move A[index, size) a slot backward
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        
        data[index] = e;
        size++;
    }
    
    // 删除索引index 的元素, 返回删除的元素
    T remove(int index) {
        assert(index >= 0 && index < size);
        
        int ret = data[index];
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
        }
        size--;
        
        if (size <= capacity / 4 && capacity / 2 != 0) {
            resize(capacity / 2);
        }
        return ret;
    }
    
    T removeFirst() {
        return remove(0);
    }
    
    T removeLast() {
        return remove(size - 1);
    }
    
    void removeElement(T e) {
        int index = find(e);
        if (index != -1) {
            remove(index);
        }
    }
    
    T get(int index) {
        assert(index >= 0 && index < size);
        return data[index];
    }
    
    void set(int index, T e) {
        assert(index >= 0 && index < size);
        data[index] = e;
    }
    
    bool contains(T e) {
        for (int i = 0; i < size; i++) {
            if (data[i] == e) {
                return true;
            }
        }
        
        return false;
    }
    
    // 查找数组中元素e所在的索引，如果不存在元素e，则返回-1
    int find(T e) {
        for (int i = 0; i < size; i++) {
            if (data[i] == e) {
                return i;
            }
        }
        
        return -1;
    }
    
    //打印数组的所有元素
    void print() {
        assert(size > 0);
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i != size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    
private:
    T *data;
    int size;       // A[0...size)
    int capacity;
    
    void resize(int newCapacity) {
        T *newData = new T[newCapacity];
        for (int i = 0; i < capacity; i++) {
            newData[i] = data[i];
        }
        capacity = newCapacity;
        delete data;
        data = newData;
    }
};

#endif /* Array_hpp */
