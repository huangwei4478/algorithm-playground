//
//  MaxHeap.hpp
//  liuyubobobo_priority_queue
//
//  Created by huangwei on 2021/1/22.
//

#ifndef MaxHeap_hpp
#define MaxHeap_hpp
#include <vector>

template <typename E>
class MaxHeap {

public:
    MaxHeap(int capacity) {
        _data.resize(capacity);
    }
    
    int size() {
        return _data.size();
    }
    
    int isEmpty() {
        return _data.empty();
    }
    
    void add(E e) {
        _data.push_back(e);
        siftUp(_data.size() - 1);
    }
    
    E findMax() {
        if (_data.empty()) { throw "Can not findMax when heap is empty."; }
        return _data[0];
    }
    
    E extractMax() {
        E ret = findMax();
        _data[0] = _data[_data.size() - 1];
        _data.pop_back();
        siftDown(0);
        return ret;
    }
private:
    std::vector<E> _data;
    
    int parent(int index) {
        if (index == 0) {
            throw "index-0 doesn't have parent.";
        }
        return (index - 1) / 2;
    }
    
    int leftChild(int index) {
        return 2 * index + 1;
    }
    
    int rightChild(int index) {
        return 2 * index + 2;
    }
    
    void siftUp(int k) {
        while (k > 0 && _data[parent(k)] < _data[k]) {
            // swap
            E temp = _data[parent(k)];
            _data[parent(k)] = _data[k];
            _data[k] = temp;
            
            // iterate
            k = parent(k);
        }
    }
    
    void siftDown(int k) {
        while (leftChild(k) < _data.size()) {
            int j = leftChild(k);
            if (j + 1 < _data.size() && _data[j + 1] > _data[j]) {
                j = rightChild(k);
            }
            // data[j] 是 leftChild 和 rightChild 的最大值
            
            if (_data[k] >= _data[j]) break;
            
            // swap
            E temp = _data[k];
            _data[k] = _data[j];
            _data[j] = temp;
            
            // iterate
            k = j;
        }
    }
    
};


#endif /* MaxHeap_hpp */
