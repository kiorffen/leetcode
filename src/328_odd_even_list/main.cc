/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/01
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
    ListNode* oddEvenList(ListNode* head) {
        if (head==NULL || head->next==NULL) {
            return head;
        }
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* sentitial = head->next;

        while (p2!=NULL&&p2->next!=NULL) {
            p1->next = p2->next;
            p2->next = p2->next->next;

            p1=p1->next;
            p2=p2->next;
        }
        p1->next=sentitial;

        return head;
    }
};

int main() {
    ListNode* l1 = new ListNode(1); 
    ListNode* l2 = new ListNode(2); 
    ListNode* l3 = new ListNode(3); 
    ListNode* l4 = new ListNode(4); 
    ListNode* l5 = new ListNode(5); 
    ListNode* l6 = new ListNode(6); 

    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = NULL;

    Solution s;
    ListNode* ret = s.oddEvenList(l1);

    ListNode* p=ret;
    while (p!=NULL) {
        cout << p->val <<" ";
        p=p->next;
    } 
    cout << endl;


    return 0;
}
