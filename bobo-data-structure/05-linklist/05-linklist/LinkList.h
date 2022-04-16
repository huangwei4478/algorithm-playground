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
        this -> dummyHead = new Node<T>(0, nullptr);
        this -> size = 0;
    }
    
    ~LinkedList() {
        deleteNode(dummyHead);
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    /// 在链表的头部添加新元素e
    void addFirst(T e) {
        add(0, e);
    }

    /// 在链表的index（0-based）位置添加新元素e
    void add(int index, T e) {
        assert(index >= 0 && index <= size);
        
        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev -> next;
        }
        
        prev -> next = new Node(e, prev -> next);
        size += 1;
    }
    
    /// 在链表的末尾添加新元素
    void addLast(T e) {
        add(size, e);
    }
    
    /// 在链表的index（0-based）位置返回元素
    T get(int index) {
        assert(index >= 0 && index < size);
        
        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev -> next;
        }
        
        return prev -> e;
    }
    
    T getFirst() {
        return get(0);
    }
    
    T getLast() {
        return get(size - 1);
    }
    
    void set(int index, T e) {
        assert(index >= 0 && index < size);
        
        Node<T> *prev = dummyHead;
        for (int i = 0; i < index; i++) {
            prev = prev -> next;
        }
        
        prev -> e = e;
    }
    
    void setFirst(T e) {
        set(0, e);
    }
    
    void setLast(T e) {
        set(size - 1, e);
    }
    
    bool contains(T e) {
        Node<T> *curr = dummyHead -> next;
        while (curr != nullptr) {
            if (curr -> e == e) {
                return true;
            }
        }
        return false;
    }
    
    void print() {
        Node<T> *prev = dummyHead;
            std::cout << "LinkedList: size = " << size << std::endl;
            std::cout << "[";
            for (int i = 0; i < size; ++i) {
                prev = prev->next;
                std::cout << prev->e;
                if (i < size - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "]" << std::endl;
        }
    
private:
    int size;
    Node<T> *dummyHead;
    
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
