/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/23
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (root==NULL) {
            return 0;
        }

        vector<int> vec;

        inorder(root,vec);

        for (auto i:vec) {
            cout << i << " ";
        }
        cout << endl;

        return vec[k-1];
    }

    void inorder(TreeNode* node, vector<int>& vec) {
        if (node->left!=NULL) {
            inorder(node->left, vec);
        }

        vec.push_back(node->val);

        if (node->right!=NULL) {
            inorder(node->right, vec);
        }
    }

    int kthSmallest1(TreeNode* root, int k) {
        int n = 0;

        if (root==NULL) {
            return 0;
        }

        stack<TreeNode*> stk;

        while (1) {
            while (root!=NULL) {
                stk.push(root);
                root = root->left;
            }

            TreeNode* node = stk.top();
            stk.pop();
            n++;
            cout << "n: " << n << " val: " << node->val << endl;
            if (n==k) {
                return node->val;
            }
            if (node->right!=NULL) {
                root = node->right;
            }
        }


    }
};

int main() {

    Solution s;

    TreeNode *root = new TreeNode(10);
    TreeNode *l11 = new TreeNode(8);
    TreeNode *l12 = new TreeNode(13);
    TreeNode *l21 = new TreeNode(7);
    TreeNode *l22 = new TreeNode(9);
    l11->left=l21;
    l11->right=l22;
    root->left=l11;
    root->right=l12;

    int ret = s.kthSmallest1(root, 3);

    cout << ret << endl;


    return 0;
}
