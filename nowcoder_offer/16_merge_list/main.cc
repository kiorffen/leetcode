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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1==NULL) {
            return pHead2;
        }
        if (pHead2==NULL) {
            return pHead1;
        }
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        
        ListNode* newHead;
        if (p1->val<=p2->val) {
            newHead=new ListNode(p1->val);
            p1=p1->next;
        } else {
            newHead=new ListNode(p2->val);
            p2=p2->next;
        }
        ListNode* p3=newHead;
        
        while (p1!=NULL&&p2!=NULL) {
            if (p1->val <= p2->val) {
                ListNode* node=new ListNode(p1->val);
                p3->next=node;
                p3=p3->next;
                p1=p1->next;
            } else {
                ListNode* node=new ListNode(p2->val);
                p3->next=node;
                p3=p3->next;
                p2=p2->next;
            }
        }
        
        while (p1!=NULL) {
            ListNode* node=new ListNode(p1->val);
            p3->next=node;
            p3=p3->next;
            p1=p1->next;
        }
        while (p2!=NULL) {
            ListNode* node=new ListNode(p2->val);
            p3->next=node;
            p3=p3->next;
            p2=p2->next;
        }
        
        return newHead;
    }
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1==NULL) {
            return pHead2;
        }
        if (pHead2==NULL) {
            return pHead1;
        }
        ListNode* p1=pHead1;
        ListNode* p2=pHead2;
        
        ListNode* newHead = new ListNode(0);
        ListNode* p3 = newHead;
        
        while (p1!=NULL&&p2!=NULL) {
            if (p1->val <= p2->val) {
                p3->next=p1;
                p1=p1->next;
                p3=p3->next;
            } else {
                p3->next=p2;
                p2=p2->next;
                p3=p3->next;
            }
        }
        
        while (p1!=NULL) {
            p3->next=p1;
            p3=p3->next;
            p1=p1->next;
        }
        while (p2!=NULL) {
            p3->next=p2;
            p3=p3->next;
            p2=p2->next;
        }
        
        return newHead->next;
    }
};
