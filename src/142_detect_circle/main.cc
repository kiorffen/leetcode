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
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        set<ListNode*> ns;
        ListNode* node=head;

        while (node!=NULL) {
            if (ns.find(node) != ns.end()) {
                return node;
            } else {
                ns.insert(node);
                node = node->next;
            }
        }

        return NULL;
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

    ListNode* ret  = s.detectCycle(l1);
    if (ret!=NULL) {
        cout << ret->val << endl;
    } else {
        cout << "no circle" << endl;
    }

    return 0;
}
