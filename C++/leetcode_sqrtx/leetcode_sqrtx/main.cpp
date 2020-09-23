//
//  main.cpp
//  leetcode_sqrtx
//
//  Created by huangwei on 2020/9/18.
//

#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
