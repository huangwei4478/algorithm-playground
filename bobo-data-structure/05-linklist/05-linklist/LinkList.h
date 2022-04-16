//
//  LinkList.h
//  05-linklist
//
//  Created by huangwei on 2022/4/14.
//

#ifndef LinkList_h
#define LinkList_h

template <typename T>
class Node {
public:
    T e;
    Node<T> *next;
    
    Node(T e, Node* next): e{ e }, next{ next } {}
    
    Node(T e): e{ e }, next{ nullptr } {}
    
    Node(): e{}, next{ nullptr } {}
};

template <typename T>
class LinkedList {
public:
    LinkedList() {
        this -> head = nullptr;
        this -> size = 0;
    }
    
    ~LinkedList() {
        deleteNode(head);
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    /// 在链表的头部添加新元素e
    void addFirst(T e) {
        head = new Node<T>(e, head);
        size += 1;
    }
    
    /// 在链表的index（0-based）位置添加新元素e
    void add(int index, T e) {
        assert(index >= 0 && index <= size);
        
        if (index == 0) {
            addFirst(e);
        } else {
            Node<T> *prev = head;
            for (int i = 0; i < (index - 1); i++) {
                prev = prev -> next;
            }
            
            Node<T> *newNode = new Node<T>(e);
            newNode -> next = prev -> next;
            prev -> next = newNode;
            size += 1;
        }
    }
    
    /// 在链表的末尾添加新元素
    void addLast(T e) {
        add(size, e);
    }
    
    
private:
    int size;
    Node<T> *head;
    
    // delete node recursively
    // fold right
    void deleteNode(Node<T> *node) {
        if (node == nullptr) {
            return;
        }
        
        if (node -> next == nullptr) {
            delete node;
            return;
        }
        
        deleteNode(node -> next);
        delete node;
        node == nullptr;
    }
};

#endif /* LinkList_h */
