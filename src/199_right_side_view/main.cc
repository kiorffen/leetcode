/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/09
* @brief  
*
**/

#include <iostream>
#include <vector>
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root==NULL) {
            return res;
        }

        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int l = q.size();
            for (int i=0;i<l;i++) {
                TreeNode* node=q.front();
                q.pop();
                if (node->left!=NULL) {
                    q.push(node->left);
                }
                if (node->right!=NULL) {
                    q.push(node->right);
                }
                if (i==l-1) {
                    res.push_back(node->val);
                }
            }
        }


        return res;
    }
};

int main() {

    Solution s;
    TreeNode *root = new TreeNode(3);
    TreeNode *l11 = new TreeNode(9);
    TreeNode *l12 = new TreeNode(20);
    TreeNode *l21 = new TreeNode(15);
    TreeNode *l22 = new TreeNode(7);
    l11->left=l21;
    root->left=l11;
    //l12->right=l22;
    root->right=l12;

    vector<int> res = s.rightSideView(root);
    for (auto i:res) {
        cout << i << endl;
    }

    return 0;
}
