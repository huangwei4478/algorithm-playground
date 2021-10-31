//
//  main.cpp
//  binary-search
//
//  Created by huangwei on 2021/10/31.
//

#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include "MyUtil.h"

using namespace std;

// 维护一个《意义》（维持了一个“循环不变量”）
// 循环不变量：在 [l...r] 的范围里，寻找target

template <typename T>
int binarySearch(T arr[], int n, T target) {
	int l = 0, r = n - 1;						// 在 [l...r] 的范围里，寻找target（确定定义是非常关键的！）
	while ( l <= r ) {							// 当 l == r 的时候，区间[l...r] 依然是有效的
		int mid = (l + r) / 2;
		if ( arr[mid] == target ) {
			return mid;
		}
		
		if ( target > arr[mid] ) {
			l = mid + 1;						// target 在 [mid + 1 ... r] 中
		} else {
			r = mid - 1;						// target 在 [l ... r - 1] 中
		}
	}
	
	return -1;
}

int main(int argc, const char * argv[]) {
	
	int n = 1000000;
	int *data = MyUtil::generateOrderedArray(n);
	
	clock_t startTime = clock();
	
	for (int i = 0; i < n; i++) {
		assert(i == binarySearch(data, n, i));
	}
	
	clock_t endTime = clock();
	
	cout << "binarySearch test complete." << endl;
	cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
	
	delete data;
		
	return 0;
}
