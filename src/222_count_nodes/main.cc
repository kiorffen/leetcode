/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/20
* @brief  
*
**/

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {        
        int ret = 0;
        if (root==NULL) {
            return ret;
        }

        queue<TreeNode*> qu;
        qu.push(root);

        while (!qu.empty()) {
            int num = qu.size();
            for (int i=0;i<num;i++) {
                TreeNode* node = qu.front();
                qu.pop();
                ret++;
                if (node->left!= NULL) {
                    qu.push(node->left);
                }
                if (node->right!= NULL) {
                    qu.push(node->right);
                }
            }
        }

        return ret;
    }

    int countNodes1(TreeNode* root) {
        if (root==NULL) {
            return 0;
        }
        int d = calDeepth(root);
        if (d==0) {
            return 1;
        }


        int left = 1, right=pow(2,d)-1;
        while (left<=right) {
            int pivot = left+(right-left)/2;
            if (check(pivot,root,d)) {
                left = pivot+1;
            } else {
                right = pivot-1;
            }
        }

        return pow(2,d)-1+left;
    }

    bool check(int p, TreeNode* root, int d) {
        TreeNode* node=root;
        int left = 0;
        int right = pow(2,d)-1;

        for (int i=0;i<d;i++) {
            int pivot = left+(right-left)/2;
            if (p>pivot) {
                node=node->right;
                left = pivot+1;
            } else {
                node=node->left;
                right = pivot;
            }
        }

        return node!=NULL;
    } 

    int calDeepth(TreeNode* root) {
        TreeNode* node = root;
        int d = 0;
        while (node->left!=NULL) {
            d++;
            node = node->left;
        }
        return d;
    }
};

int main() {

    TreeNode *root = new TreeNode(3);
    TreeNode *l11 = new TreeNode(9);
    TreeNode *l12 = new TreeNode(20);
    TreeNode *l21 = new TreeNode(15);
    TreeNode *l22 = new TreeNode(7);
    l11->left=l21;
    l11->right=l22;
    root->left=l11;
    root->right=l12;

    Solution s;
    int ret = s.countNodes1(root);

    cout << ret << endl;


    return 0;
}
