// leetcode_template.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>

using namespace std;

class Solution_find_difference {
 public:
    char findTheDifference(string s, string t) {
        char ret = 0;

        for (auto ch : s + t) {
            ret ^= ch;
        }

        return ret;
    }        
};


int main()
{
    std::cout << "Hello World!\n";
}
