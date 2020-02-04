/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/17
* @brief  
*
**/

#include <cstdio>
#include <cstdlib>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) {
            return NULL;
        }
        ListNode *cur = head;
        ListNode *pre = head;
        for (int i = 0; i < n; i++) {
            cur = cur->next;
        }
        if (cur == NULL) {
            return head->next;
        }
        while (cur->next != NULL) {
            cur = cur->next;
            pre = pre->next;
        }
        pre->next = pre->next->next;
        return head;
    }
};

int main() {
    ListNode *head;
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    head->next = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    ListNode *p = head->next;
    printf("1-%d\n", p->val);
    p = p->next;
    printf("2-%d\n", p->val);
    while(p->next != NULL) {
        printf("ss");
        p = p->next;
    }

    Solution s;
    ListNode* ret = s.removeNthFromEnd(head, 2);
    while(ret->next != NULL) {
        printf("%d\n", ret->val);
        ret = ret->next;
    }

    return 0;
}
