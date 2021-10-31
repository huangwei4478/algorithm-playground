//
//  MyUtil.h
//  binary-search
//
//  Created by huangwei on 2021/10/31.
//

#ifndef MyUtil_h
#define MyUtil_h

namespace MyUtil {
	int *generateRandomArray(int n, int rangeL, int rangeR) {
		assert( n > 0 && rangeL <= rangeR );
		
		int *arr = new int[n];
		
		srand(time(NULL));
		
		for (int i = 0; i < n; i++) {
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		}
		return arr;
	}
	
	int *generateOrderedArray(int n) {
		assert(n > 0);
		
		int *arr = new int[n];
		
		for (int i = 0; i < n; i++) {
			arr[i] = i;
		}
		
		return arr;
	}
}

#endif /* MyUtil_h */
