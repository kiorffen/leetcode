/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/12
* @brief  
*
**/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        int ret = 0;
        int one = 0;
        dfs(root, ret, one);

        return ret;
    }

    void dfs(TreeNode *node, int &num, int one) {
        int pre = one;
        one = one*10 + node->val;
        if (node->left == NULL && node->right== NULL) {
            cout << "one: " << one << endl;
            num = num + one;
        }

        if (node->left != NULL) {
            dfs(node->left, num, one);
        }
        if (node->right != NULL) {
            dfs(node->right, num, one);
        }

        one = pre;
    }
};

int main() {
    Solution s;
    TreeNode *root = new TreeNode(3);
    TreeNode *l11 = new TreeNode(9);
    TreeNode *l12 = new TreeNode(2);
    TreeNode *l21 = new TreeNode(5);
    TreeNode *l22 = new TreeNode(7);
    root->left=l11;
    l12->left=l21;
    l12->right=l22;
    root->right=l12;

    int ret = s.sumNumbers(root);

    cout << "ret: " << ret << endl;

    return 0;
}
