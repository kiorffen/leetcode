/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/04
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
    ListNode* insertionSortList(ListNode* head) {
        if (head==NULL || head->next==NULL) {
            return head;
        }

        ListNode* newHead = new ListNode(1);
        ListNode* cur = head;

        while (cur!=NULL) {
            cout << cur->val << endl;
            ListNode* p2 = newHead;
            while (p2->next!=NULL && p2 ->next->val <= cur->val) {
                    p2=p2->next;
            }
            ListNode* tmp = cur->next;
            cur->next = p2->next;
            p2->next = cur;
            cur = tmp;
        }
        return newHead->next;
    }

};

int main() {

    Solution s;

    ListNode* l1 = new ListNode(8); 
    ListNode* l2 = new ListNode(2); 
    ListNode* l3 = new ListNode(9); 
    ListNode* l4 = new ListNode(4); 

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = NULL;

    ListNode* ret = s.insertionSortList(l1);
    ListNode* p = ret;
    while (p!=NULL) {
        cout << p->val << " ";
        p=p->next;
    }
    cout << endl;

    return 0;
}
