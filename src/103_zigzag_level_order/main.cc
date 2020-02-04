/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/01
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (root == NULL) {
            return res;
        }

        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);

        while(!s1.empty() || !s2.empty()) {
            vector<int> tmp;
            int n = s1.size();
            for (int i =0;i<n;i++) {
                auto node = s1.top();
                s1.pop();
                tmp.push_back(node->val);
                if (node->left!=NULL) {
                    s2.push(node->left);
                }
                if (node->right!=NULL) {
                    s2.push(node->right);
                }
            }
            if (tmp.size()>0) {
                res.push_back(tmp);
            }
            vector<int> tmp1;
            int m = s2.size();
            for (int j=0;j<m;j++) {
                auto node=s2.top();
                s2.pop();
                tmp1.push_back(node->val);
                if(node->right!= NULL) {
                    s1.push(node->right);
                }
                if(node->left!=NULL) {
                    s1.push(node->left);
                }
            }
            if (tmp1.size()>0) {
                res.push_back(tmp1);
            }
        }

        return res;
    }
};

int  main() {
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

    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for (auto v:res) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
