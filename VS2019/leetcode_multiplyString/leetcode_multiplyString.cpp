// leetcode_multiplyString.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        // handle edge-case where the product is 0
        if (num1 == "0" || num2 == "0") return "0";
        int m = num1.size();
        int n = num2.size();
        vector<int> result(m + n, 0);
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;

                int sum = prod + result[p2];

                result[p1] += sum / 10;
                result[p2] = sum % 10;
            }
        }
        string str = "";

        for (int i = 0; i < result.size(); i++) {
            // skip all the starting 0's
            if (!(result[i] == 0 && str.length() == 0)) {
                str += to_string(result[i]);
            }
        }

        return str.length() == 0 ? "0" : str;

    }
};
int main()
{
    std::cout << "Hello World!\n";
}

