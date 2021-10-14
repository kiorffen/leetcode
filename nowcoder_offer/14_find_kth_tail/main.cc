/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/06
* @brief  
*
**/

#include <iostream>

using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode* fast=pListHead;
        ListNode* slow=pListHead;
        
        int cnt=0;
        while (cnt<k) {
            if (fast!=NULL) {
                fast=fast->next;
            }else {
                return NULL;
            }
            cnt++;
        }
        
        while (fast!=NULL) {
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
    }
};

int main() {
    Solution s;

    ListNode* root=new ListNode(1);
    ListNode* node1=new ListNode(2);
    ListNode* node2=new ListNode(3);
    ListNode* node3=new ListNode(4);
    ListNode* node4=new ListNode(5);
    root->next=node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    ListNode* p=root;
    while (p!=NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;

    ListNode* ret = s.FindKthToTail(root,4);
    cout << ret->val << endl;

    return 0;
}
