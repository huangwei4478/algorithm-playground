//
//  Array.h
//  01-Array
//
//  Created by 黄炜 on 2022/6/17.
//

#ifndef Array_h
#define Array_h

#include <iostream>
#include <cassert>

template <typename T>
class Array {
public:
    Array(int capacity) {
        data = new T[capacity];
        size = 0;
        this -> capacity = capacity;
    }
    
    Array(): Array(0) {}
    
    ~Array() {
        delete[] data;
    }
    
    int getSize() {
        return size;
    }
    
    int getCapacity() {
        return capacity;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    void addLast(T e) {
        add(size, e);
    }
    
    void addFirst(T e) {
        add(0, e);
    }
    
    void add(int index, int e) {
        if (size == capacity) {
            throw std::invalid_argument("Add failed, array is full.");
        }
        
        if (index < 0 || index > size) {
            throw std::invalid_argument("Add failed, require index >= 0 and index <= size");
        }
        
        for (int i = size - 1; i >= index; i--) {
            data[i + 1] = data[i];
        }
        
        data[index] = e;
        size++;
    }
    
    T get(int index) {
        if (index < 0 || index >= size) {
            throw std::invalid_argument("Get failed, require index >= 0 and index < size");
        }
        
        return data[index];
    }
    
    void set(int index, T e) {
        if (index < 0 || index >= size) {
            throw std::invalid_argument("Set failed, require index >= 0 and index < size");
        }
        
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
    
    int find(T e) {
        for (int i = 0; i < size; i++) {
            if (data[i] == e) {
                return i;
            }
        }
        return -1;
    }
    
    T remove(int index) {
        if (index < 0 || index >= size) {
            throw std::invalid_argument("Remove failed, index is illegal.");
        }
        
        int ret = data[index];
        for (int i = index + 1; i < size; i++) {
            data[i - 1] = data[i];
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
    
    
    
    void print() {
        std::cout << "Array: size = " << size << ", capacity = " << getCapacity() << std::endl;
        std::cout << "[";
        for (int i = 0; i < size; ++i) {
            std::cout << data[i];
            if (i != size - 1) {
                std::cout << ",";
            }
        }
        std::cout << "]";
        std::cout << std::endl;
    }
    
private:
    T *data;
    int size;
    int capacity;
};

#endif /* Array_h */
