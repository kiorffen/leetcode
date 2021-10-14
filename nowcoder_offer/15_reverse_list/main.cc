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

/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead==NULL || pHead->next==NULL) {
            return pHead;
        }
        
        ListNode* pre = NULL;
        ListNode* cur = pHead;
        
        while (cur!=NULL) {
            ListNode* tmp=cur->next;
            cur->next = pre;
            pre=cur;
            cur=tmp;
        }
        
        return pre;
    }
};

class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead==NULL || pHead->next==NULL) {
            return pHead;
        }
        
        ListNode* head = ReverseList(pHead->next);
        
        pHead->next->next=pHead;
        pHead->next=NULL;
        
        return head;
    }
};
