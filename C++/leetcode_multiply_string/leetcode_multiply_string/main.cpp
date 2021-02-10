//
//  main.cpp
//  leetcode_multiply_string
//
//  Created by huangwei on 2021/2/9.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1.size() == 0 && num2.size() == 0) return "";
        if (num1 == "0" || num2 == "0") return "0";
        
        int m = num1.size();
        int n = num2.size();
        
        vector<int> result(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int p1 = i + j, p2 = i + j + 1;
                
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product += result[p2];
                
                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }
        
        string ans;
        for (int i = 0; i < (m + n); i++) {
            if (!(ans.size() == 0 && result[i] == 0)) {
                ans += to_string(result[i]);
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
