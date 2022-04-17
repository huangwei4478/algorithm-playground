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
private:
    Node<T>* root;
    int size;
};

#endif /* BST_h */
