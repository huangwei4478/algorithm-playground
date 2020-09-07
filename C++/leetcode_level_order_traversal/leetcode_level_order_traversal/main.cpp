//
//  main.cpp
//  leetcode_level_order_traversal
//
//  Created by huangwei on 2020/8/28.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node* root) {
    if (root == nullptr) { return {}; }     // C++ 11
    vector<vector<int>> res;                // result
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        int size = int(q.size());           // 我就是这一步没想清楚
        vector<int> curLevel;
        for (int i = 0; i < size; i++) {
            Node *temp = q.front();
            q.pop();
            curLevel.push_back(temp -> val);
            for (auto n: temp -> children) {
                q.push(n);
            }
        }
        res.push_back(curLevel);
    }
    
    return res;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
