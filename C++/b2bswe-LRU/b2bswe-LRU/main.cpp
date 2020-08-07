//
//  main.cpp
//  b2bswe-LRU
//
//  Created by huangwei on 2020/8/6.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

struct DLinkedNode {
    int key, value;
    DLinkedNode *prev, *next;
    DLinkedNode() : key { 0 }, value { 0 }, prev { nullptr }, next { nullptr } {}
    DLinkedNode(int _key, int _value): key { _key }, value { _value }, prev { nullptr }, next { nullptr } {}
};

class LRUCache {
private:
    std::unordered_map<int, DLinkedNode*> cache;                        // 哦哦？这种类不用在constructor里写明init， 现在已经初始化好了
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    const int capacity;
public:
    LRUCache(int capacity) : capacity { capacity }, size { 0 } {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    ~LRUCache() {
        delete head;
        delete tail;
    }
    
    int get(int key) {
        if (cache.count(key) == 0) {
            return -1;                  // cache miss
        }
        // cache hit, move to front
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
        } else {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }
    
    void addToHead(DLinkedNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    // delete is so damn fast!
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
};

int main(int argc, const char * argv[]) {
    // insert code here...
    /**
     ["LRUCache","put","put","get","put","get","put","get","get","get"]
     [[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]
     
     */
    LRUCache lru{3};
    lru.put(1, 1);
    lru.put(2, 2);
    lru.get(1);
    lru.put(3, 3);
    lru.get(2);
    lru.put(4, 4);
    lru.get(1);
    lru.get(3);
    lru.get(4);
    
    return 0;
}
