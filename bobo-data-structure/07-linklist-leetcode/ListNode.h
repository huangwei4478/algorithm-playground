//
// Created by huangwei on 2022/4/17.
//

#ifndef INC_07_LINKLIST_LEETCODE_LISTNODE_H
#define INC_07_LINKLIST_LEETCODE_LISTNODE_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;

        ListNode *prev = dummyHead;

        while (prev != nullptr) {
            if (prev -> next -> val == val) {
                ListNode *toBeDeletedNode = prev -> next;
                prev -> next = toBeDeletedNode -> next;
                delete toBeDeletedNode;
                toBeDeletedNode = nullptr;
            } else {
                prev = prev->next;
            }
        }

        return dummyHead->next;
    }
};

class Solution_Recursive {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) { return nullptr; }
        head -> next = removeElements(head -> next, val);
        return head -> val == val ? head -> next : head;
    }
};

#endif //INC_07_LINKLIST_LEETCODE_LISTNODE_H
