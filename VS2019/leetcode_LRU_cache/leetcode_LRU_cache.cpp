// leetcode_LRU_cache.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>

using namespace std;

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev, * next;
    DLinkedNode() : key{ 0 }, value{ 0 }, prev{ nullptr }, next{ nullptr } {}
    DLinkedNode(int _key, int _value) : key{ _key }, value{ _value }, prev{ nullptr }, next{ nullptr } {}
};

class LRUCache {
private:
    std::unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;

    int size;

    const int capacity;

    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }

    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

public:
    LRUCache(int capacity) : capacity{ capacity }, size{ 0 } {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        DLinkedNode* curr = head->next;
        while (curr) {
            DLinkedNode* next = curr->next;
            delete curr;
            curr = next;
        }
    }

    int get(int key) {
        if (cache.count(key) == 0) return -1;

        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (!cache.count(key)) {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size++;
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
            }
        }
        else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }


};


