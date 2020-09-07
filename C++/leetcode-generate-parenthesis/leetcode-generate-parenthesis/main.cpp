//
//  main.cpp
//  leetcode-generate-parenthesis
//
//  Created by huangwei on 2020/8/28.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


void dfs(string curStr, int left, int right, vector<string>& res) {
    if (left == 0 && right == 0) {
        res.push_back(curStr);
        return;
    }
    
    // 剪枝（如果右边括号的剩余数少于做括号，那么就怎么都凑不齐的）
    if (left > right) return;
    
    if (left > 0) {
        dfs(curStr + "(", left - 1, right, res);
    }
    
    if (right > 0) {
        dfs(curStr + ")", left, right - 1, res);
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> res;
    
    if (n == 0) { return res; }
    
    // 执行深度优先遍历，搜索可能的全部结果
    dfs("", n, n, res);
    
    return res;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
