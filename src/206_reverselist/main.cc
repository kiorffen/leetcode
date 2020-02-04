/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/22
* @brief  
*
**/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;

        return p;
    }

    ListNode* reverseList1(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* pre = NULL;
        ListNode* temp = head;

        while(temp != NULL) {
            ListNode* node = temp->next;
            temp->next = pre;
            pre = temp;
            temp = node;
        }

        return pre;
    }

};

int main() {

    Solution s;

    ListNode* l1 = new ListNode(3); 
    ListNode* l2 = new ListNode(1); 
    ListNode* l3 = new ListNode(2); 
    ListNode* l4 = new ListNode(-4); 

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    ListNode* ret  = s.reverseList1(l1);
    while (ret != NULL) {
        cout << ret->val<<endl;
        ret = ret->next;
    }

    return 0;
}
