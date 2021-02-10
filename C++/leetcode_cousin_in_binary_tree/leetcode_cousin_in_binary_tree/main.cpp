//
//  main.cpp
//  leetcode_cousin_in_binary_tree
//
//  Created by huangwei on 2021/2/9.
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
    unordered_map<int, int> depthMap;
    unordered_map<int, TreeNode*> parentMap;
    
    void dfs(TreeNode* node, TreeNode* parrent) {
        if (node == nullptr) return;
        
        if (parrent == nullptr) {
            depthMap[node -> val] = 0;
        } else {
            depthMap[node -> val] = depthMap[parrent -> val] + 1;
        }
        
        parentMap[node -> val] = parrent;
        
        dfs(node -> left, node);
        dfs(node -> right, node);
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (root == nullptr) return false;
        dfs(root, nullptr);
        return (depthMap[x] == depthMap[y]) && (parentMap[x] != parentMap[y]);
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
