//
//  main.cpp
//  leetcode_cycle_link_list_ii
//
//  Created by huangwei on 2020/8/14.
//  Copyright © 2020 huangwei. All rights reserved.
//

#include <iostream>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return nullptr;

        ListNode* slowPtr = head;
        ListNode* fastPtr = head -> next;

        while (slowPtr != fastPtr) {
            if (fastPtr == NULL || fastPtr -> next == NULL) return nullptr;
            
            slowPtr = slowPtr -> next;
            fastPtr = fastPtr -> next -> next;
        }

        // look for the first node of the ring
        ListNode *meetPtr = slowPtr;
        ListNode *headNode = head;
        while (meetPtr != headNode) {
            printf("meetPtr = %i, headNode = %i\n", meetPtr->val, headNode->val);
            meetPtr = meetPtr -> next;
            headNode = headNode -> next;
        }

        return meetPtr;
    }
};


int main(int argc, const char * argv[]) {
    ListNode *node1 = new ListNode(3);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(0);
    ListNode *node4 = new ListNode(-4);
    
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node2;
    Solution solution;
    ListNode *meetNode = solution.detectCycle(node1);
    std::cout << meetNode -> val << std::endl;
    return 0;
}
