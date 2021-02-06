// leetcode_string_compression.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        if (n <= 1) return n;
        
        int i = 0;
        for (int j = 0; j < n; j++) {
            int count = 1;

            // check if there is a cluster of the same elements
            while (j < n - 1 && chars[j] == chars[j + 1]) {
                count++;
                j++;
            }
            
            // i: the correct position to add characters
            chars[i++] = chars[j];
            
            // i: the correct position to add count
            if (count > 1) {
                for (auto d : to_string(count)) {
                    chars[i++] = d;
                }
            }
        }
        return i;
    }
};