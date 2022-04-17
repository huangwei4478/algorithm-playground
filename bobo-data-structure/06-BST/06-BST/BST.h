//
//  BST.h
//  06-BST
//
//  Created by huangwei on 2022/4/17.
//

#ifndef BST_h
#define BST_h

template <typename T>
class Node {
public:
    T e;
    Node* left;
    Node* right;
    
    Node(T e) {
        this -> e = e;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST {
public:
    BST() {
        root = nullptr;
        size = 0;
    }
    
    void add(T e) {
        if (root == nullptr) {
            root = new Node<T>(e);
            return;
        }
        
        add(root, e);
    }
    
    bool contains(T e) {
        return contains(root, e);
    }
    
private:
    Node<T>* root;
    int size;
    
    Node<T>* add(Node<T> *node, T e) {
        if (node == nullptr) {
            return new Node<T>(e);
            size += 1;
        } else {
            if (e < node -> val) {
                node -> left = add(node -> left, e);
            } else if (e > node -> val) {
                node -> right = add(node -> right, e);
            }
            
            return node;
        }
    }
    
    /// 以Node 为节点开始寻找，有没有元素e
    /// 挂靠在 Node 节点以内的树中
    bool contains(Node<T> *node, T e) {
        if (node == nullptr) { return false; }
        
        if (node -> e == e) {
            return true;
        } else if (e < node -> e) {
            return contains(node -> left, e);
        } else {
            return contains(node -> right, e);
        }
    }
};

#endif /* BST_h */
