/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/04
* @brief  
*
**/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (root==NULL) {
            return ret;
        }

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node=st.top();
            st.pop();
            ret.push_back(node->val);
            if (node->right!=NULL) {
                st.push(node->right);
            }
            if (node->left!=NULL) {
                st.push(node->left);
            }
        }

        return ret;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    TreeNode *l11 = new TreeNode(9);
    TreeNode *l12 = new TreeNode(20);
    TreeNode *l21 = new TreeNode(15);
    TreeNode *l22 = new TreeNode(7);
    root->left=l11;
    l12->left=l21;
    l12->right=l22;
    root->right=l12;

    vector<int> ret = s.preorderTraversal(root);

    for (auto i:ret) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
