// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

 struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 

#include <iostream>



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode();
        ListNode* p = dummyHead;
        ListNode* p1 = l1, *p2 = l2;

        int carry = 0;

        int sum = 0;

        while (p1 != nullptr || p2 != nullptr || carry > 0) {
            sum = (p1 == nullptr ? 0 : p1->val) +
                (p2 == nullptr ? 0 : p2->val) +
                carry;

            carry = sum / 10;

            p->next = new ListNode(sum % 10);

            p1 = p1 == nullptr ? nullptr : p1->next;
            p2 = p2 == nullptr ? nullptr : p2->next;

            p = p->next;
        }
        return dummyHead->next;
    }
};


int main()
{
    std::cout << "Hello World!\n";
}

