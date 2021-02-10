//
//  main.cpp
//  leetcode_string_compression
//
//  Created by huangwei on 2021/2/9.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() == 0) return 0;
        
        int i = 0;
        
        int N = chars.size();
        for (int j = 0; j < N; j++) {
            int count = 1;
            while (j + 1 < N && chars[j] == chars[j + 1]) {
                count++;
                j++;
            }
            
            chars[i++] = chars[j];
            
            if (count > 1) {
                for (auto d: to_string(count)) {
                    chars[i++] = d;
                }
            }
        }
        return i;
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
