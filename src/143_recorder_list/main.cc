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
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL || head->next->next==NULL) {
            return;
        }

        stack<ListNode*> ns;
        ListNode* p = head;
        while (p!=NULL) {
            ns.push(p);
            p=p->next;
        }

        p = head;
        int size = ns.size();
        for (int i = 0;i<size/2; i++) {
            ListNode* node = p->next;
            p->next = ns.top();
            ns.pop();
            p->next->next = node;
            p=node;
        }
        p->next=NULL;
    }
};

int main() {

    Solution s;

    ListNode* l1 = new ListNode(1); 
    ListNode* l2 = new ListNode(2); 
    ListNode* l3 = new ListNode(3); 
    //ListNode* l4 = new ListNode(4); 

    l1->next = l2;
    l2->next = l3;
    l3->next = NULL;
    //l4->next = NULL;

    s.reorderList(l1);
    ListNode* ret = l1;
    while (ret != NULL) {
        cout << ret->val<<endl;
        ret = ret->next;
    }

    return 0;
}
