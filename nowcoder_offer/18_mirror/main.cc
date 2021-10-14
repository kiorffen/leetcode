/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/06
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
    void Mirror(TreeNode *pRoot) {
        if (pRoot==NULL) {
            return;
        }
        if (pRoot->left==NULL && pRoot->right==NULL) {
            return;
        }
        TreeNode* tmp = pRoot->left;
        pRoot->left=pRoot->right;
        pRoot->right = tmp;
        if (pRoot->left!=NULL) {
            Mirror(pRoot->left);
        }
        
        if (pRoot->right!=NULL) {
            Mirror(pRoot->right);
        }
    }
};
