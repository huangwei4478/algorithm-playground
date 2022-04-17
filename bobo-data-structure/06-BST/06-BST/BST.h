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
            } else {
                return node;
            }
        }
    }
};

#endif /* BST_h */
