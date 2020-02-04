/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/04
* @brief  
*
**/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (root==NULL) {
            return res;
        }

        vector<int> one;
        dfs(root,sum, res, one);

        return res;
    }

    void dfs(TreeNode* node,int sum, vector<vector<int>> &res, vector<int> &one) {
        one.push_back(node->val);
        sum=sum-(node->val);
        if (node->left==NULL && node->right==NULL) {
            if (sum == 0) {
                res.push_back(one);
                return;
            }
        }

        if (node->left!=NULL) {
            dfs(node->left, sum, res, one);
        }

        if (node->right!=NULL) {
            dfs(node->right, sum, res, one);
        }
        one.pop_back();
        sum=sum+(node->val);
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

    vector<vector<int>> res = s.pathSum(root,38);

    for (auto v:res) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
