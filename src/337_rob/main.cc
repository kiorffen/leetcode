/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/10
* @brief  
*
**/

#include <iostream>
#include <map>
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
    int rob(TreeNode* root) {
        map<TreeNode*,int> mp;
        int result = robInner(root,mp);
        return result;
    }

    int robInner(TreeNode* root, map<TreeNode*,int>& mp) {
        if (root==NULL) {
            return 0;
        }
        auto it = mp.find(root);
        if (it!=mp.end()) {
            return mp[root];
        }

        int money=0;
        money+=root->val;
        if (root->left!=NULL) {
            money=money+robInner(root->left->left,mp)+robInner(root->left->right,mp);
        }
        if (root->right!=NULL) {
            money=money+robInner(root->right->left,mp)+robInner(root->right->right,mp);
        }

        int result = max(money, robInner(root->left,mp)+robInner(root->right,mp));

        mp[root] = result;

        return result;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    TreeNode *l11 = new TreeNode(2);
    TreeNode *l12 = new TreeNode(3);
    TreeNode *l21 = new TreeNode(3);
    TreeNode *l22 = new TreeNode(1);
    l11->right=l21;
    root->left=l11;
    l12->right=l22;
    root->right=l12;

    int cash = s.rob(root);
    cout << cash << endl;


    return 0;
}
