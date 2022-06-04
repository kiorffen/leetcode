/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2022/03/08
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct ListNode {
    ListNode *next;
    int val;
    ListNode(int _val):val(_val) {
        next = NULL;
    }
};

ListNode* reverse_linklist(ListNode *head) {
    if (head == NULL || head->next==NULL) {
        return head;
    }
    ListNode *p=NULL, *q=head;

    while(q!=NULL) {
        ListNode *temp = q->next;
        q->next = p;
        p=q;
        q=temp;
    }

    return p;
}

ListNode* reverse_linklist_k(ListNode *head, int k) {
    ListNode *end = head;
    ListNode *q = NULL, *p=NULL, *pp=NULL;
    ListNode *new_head = NULL;
    bool first=true;
    bool finished = false;

    while(end != NULL) {
        p = end;
        for (int i=0;i<k;i++) {
            q=end;
            end=end->next;
            if (end==NULL && i<k-1) {
                cout << "finished: " << i << endl;
                finished = true;
                break;
            }
        }
        if (finished) {
            cout << "finished" << endl;
            break;
        }
        cout << "p q:" << p->val << " " << q->val << endl;
        // duankai 
        q->next=NULL;

        // xuanzhuan
        if (pp!=NULL) {
            pp->next=q;
        }
        ListNode *new_sub=reverse_linklist(p);
        if (first) {
            new_head=new_sub;
            first=false;
        }
        // zhi xiang xia yi duan
        p->next=end;
        pp=p;

    }

    if (pp==NULL) {
        cout << "heer" << endl;
        return head;
    }

    return new_head;
}

int main() {
    ListNode *n1= new ListNode(1);
    ListNode *n2= new ListNode(2);
    ListNode *n3= new ListNode(3);
    ListNode *n4= new ListNode(4);
    ListNode *n5= new ListNode(5);
    ListNode *n6= new ListNode(6);
    ListNode *n7= new ListNode(7);
    ListNode *n8= new ListNode(8);
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=n6;
    n6->next=n7;
    n7->next=n8;

    ListNode *res=reverse_linklist_k(n1,3);

    ListNode *p=res;
    cout << "res: ";
    while(p!=NULL) {
        cout << p->val << " ";
        p=p->next;
    } 
    cout << endl;
}

