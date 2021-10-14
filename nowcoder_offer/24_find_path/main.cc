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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        if (root==NULL) {
            return res;
        }
        vector<int> one;
        dfs(root,expectNumber,one,res);
        
        return res;
    }
    
    void dfs(TreeNode* root, int en, vector<int>& one, vector<vector<int>>& res) {
        en = en - root->val;
        if (en==0 && root->left==NULL && root->right==NULL) {
            one.push_back(root->val);
            res.push_back(one);
            one.pop_back();
            return;
        }
        if (en>0) {
            one.push_back(root->val);
            if (root->left!=NULL) {
                dfs(root->left, en, one, res);
            }
            if (root->right!=NULL) {
                dfs(root->right, en, one,res);
            }
            one.pop_back();
        }
    }
};
