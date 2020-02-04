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
#include <iostreamo>
#include <vector>

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
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        find(root,res);

        return res;
    }

    void find(TreeNode* node, vector<int> &res) {
        if (node->left!=NULL) {
            find(node->left);
        }
        res.push_back(node->val);
        if (node->right != NULL) {
            find(node->right);
        }

    }
};
