// leetcode_cousins_in_binary_tree.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
private:

    /*
        parent[node.val] = par
        depth[node.val] = d
    */

    unordered_map<int, int> depthMap;
    unordered_map<int, TreeNode*> parentMap;
    
    void dfs(TreeNode* node, TreeNode* parent) {
        if (node != nullptr) {
            depthMap.insert({ node->val, parent != nullptr ? 1 + depthMap[parent->val] : 0 });
            parentMap.insert({ node->val, parent });
            dfs(node->left, node);
            dfs(node->right, node);
        }
    }

public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        dfs(root, nullptr);
        return (depthMap[x] == depthMap[y] && parentMap[x] != parentMap[y]);
    }
};
