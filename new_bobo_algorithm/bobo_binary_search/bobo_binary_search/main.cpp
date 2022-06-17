//
//  main.cpp
//  bobo_binary_search
//
//  Created by 黄炜 on 2022/6/14.
//

#include <iostream>

using namespace std;

template <typename T>
int binarySearch(T arr[], int n, T target) {
    int l = 0, r = n - 1;       // 在 [l ... r] 区间内寻找target
    while (l <= r) {            // 当 l == r 的时候，区间[l ... r] 依旧是有效的
        int mid = l + (r - l) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (target > arr[mid]) {
            l = mid + 1;        // target 在 [mid + 1 ... r] 中
        } else {
            r = mid - 1;        // target 在 [l ... mid - 1] 中
        }
    }
    
    return -1;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
