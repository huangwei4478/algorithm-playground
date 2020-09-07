//
//  main.cpp
//  leetcode-build-binary-search-tree-from-preorder-inorder-list
//
//  Created by huangwei on 2020/8/29.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    unordered_map<int, int> index;
    
    TreeNode* _buildTree(const vector<int>& preorder,
                         const vector<int>& inorder,
                         int preorder_left,
                         int preorder_right,
                         int inorder_left,
                         int inorder_right) {
        if (preorder_left > preorder_right) { return nullptr; }
        
        // 前序遍历的第一个节点就是根节点
        int preorder_root = preorder_left;
        int inorder_root = index[preorder[preorder_root]];
        
        TreeNode *root = new TreeNode(preorder[preorder_root]);
        int size_left_subtree = inorder_root - inorder_left;
        root -> left = _buildTree(preorder, inorder, preorder_left + 1, preorder_left + size_left_subtree,
                                  inorder_left, inorder_root - 1);
        root -> right = _buildTree(preorder, inorder, preorder_left + size_left_subtree + 1, preorder_right,
                                   inorder_root + 1, inorder_right);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = int(preorder.size());
        for (int i = 0; i < n; ++i) {
            index[inorder[i]] = i;
        }
        return _buildTree(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
