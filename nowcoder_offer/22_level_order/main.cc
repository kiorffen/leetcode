/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/07
* @brief  
*
**/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if (root==NULL) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i=0;i<len;i++) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);
                if (node->left!=NULL) {
                    q.push(node->left);
                } 
                if (node->right!=NULL) {
                    q.push(node->right);
                }
            }
        }
        
        return res;
    }
};
