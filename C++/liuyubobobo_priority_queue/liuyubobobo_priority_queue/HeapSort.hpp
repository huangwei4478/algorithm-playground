//
//  HeapSort.hpp
//  liuyubobobo_priority_queue
//
//  Created by huangwei on 2021/1/22.
//

#ifndef HeapSort_hpp
#define HeapSort_hpp

#include <vector>
#include "MaxHeap.hpp"

using namespace std;

template <typename E>
class HeapSort {
private:
    HeapSort() {}
public:
    static void sort(vector<E>& data) {
        MaxHeap<E> maxHeap = MaxHeap<E>(data.size());
        
        for (E e : data) {
            maxHeap.add(e);
        }
        
        for (int i = data.size() - 1; i >= 0; i --) {
            data[i] = maxHeap.extractMax();
        }
    }
};

#endif /* HeapSort_hpp */
