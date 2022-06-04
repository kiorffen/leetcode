/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2022/03/05
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    char val;
    TreeNode(char _val):val(_val) {
        left=NULL;
        right=NULL;
    }
};

void btree_zscan(TreeNode *root) {
    queue<TreeNode*> q;
    stack<TreeNode*> s1,s2;

    s1.push(root);
    while(s1.size() > 0 || s2.size() > 0) {
        while(s1.size() > 0) {
            TreeNode *node = s1.top(); s1.pop();
            cout << node->val << " ";
            if (node->left != NULL) {
                s2.push(node->left);
            }
            if (node->right != NULL) {
                s2.push(node->right);
            }
        }

        while (s2.size() > 0) {
            TreeNode *node = s2.top(); s2.pop();
            cout << node->val << " ";
            if (node->right != NULL) {
                s1.push(node->right);
            }
            if (node->left != NULL) {
                s1.push(node->left);
            }
        }
    }
    cout << endl;
}

int main() {
    TreeNode *root = new TreeNode('A');
    TreeNode *n1 = new TreeNode('B');
    TreeNode *n2 = new TreeNode('C');
    TreeNode *n3 = new TreeNode('E');
    TreeNode *n4 = new TreeNode('F');
    TreeNode *n5 = new TreeNode('G');
    TreeNode *n6 = new TreeNode('J');
    TreeNode *n7 = new TreeNode('K');
    TreeNode *n8 = new TreeNode('M');
    TreeNode *n9 = new TreeNode('N');
    root->left=n1;
    root->right=n2;
    n1->right=n3;
    n2->left=n4;
    n2->right=n5;
    n3->left=n6;
    n3->right=n7;
    n4->right=n8;
    n5->left=n9;

    btree_zscan(root);

    return 0;
}
