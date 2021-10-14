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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (pRoot1==NULL || pRoot2==NULL) {
            return false;
        }
        
        if (pRoot1->val==pRoot2->val && isSame(pRoot1, pRoot2)==true) {
            return true;
        }
        
        return HasSubtree(pRoot1->left,pRoot2) || HasSubtree(pRoot1->right,pRoot2);
    }
    
    bool isSame(TreeNode* root1, TreeNode* root2) {
        if (root2==NULL) {
            return true;
        }
        if (root1==NULL) {
            return false;
        }
        if (root1->val!=root2->val) {
            return false;
        }
        return isSame(root1->left,root2->left) && isSame(root1->right, root2->right);
    }
};
