/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/27
* @brief  
*
**/

/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> res;
        if (head==NULL) {
            return res;
        }
        
        ListNode* pre=NULL;
        ListNode* cur=head;
        
        while (cur!=NULL) {
            ListNode* tmp=cur->next;
            cur->next=pre;
            pre=cur;
            cur=tmp;
        }
        
        ListNode* p=pre;
        while (p!=NULL) {
            res.push_back(p->val);
            p=p->next;
        }
        
        return res;
    }
};
