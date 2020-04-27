/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/27
* @brief  
*
**/

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
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        int root_index=0;
        TreeNode* root=buildTree(root_index,pre,vin);
        return root;
    }
    
    TreeNode* buildTree(int root_index, vector<int>& pre, vector<int>& vin) {
        if (root_index>=pre.size() || vin.size()==0) {
            return NULL;
        }
        cout << "root_index"<< root_index<<endl;
        int data = pre[root_index];
        TreeNode* node=new TreeNode(data);
        vector<int> left;
        vector<int> right;
        
        int flag=0;
        for (auto i:vin) {
            if (i!=data&&flag==0) {
                left.push_back(i);
            } else if (i!=data&&flag==1) {
                right.push_back(i);
            } else if (i==data) {
                flag=1;
            }
        }
        
        node->left=buildTree(root_index+1,pre,left);
        node->right=buildTree(root_index+left.size()+1,pre,right);
        
        return node;
    }

    void printTree(TreeNode* root) {
        if (root==NULL) {
            return;
        }
        cout << root->val << endl;
        printTree(root->left);
        printTree(root->right);
    }
};

int main() {
    Solution s;

    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};

    TreeNode* root = s.reConstructBinaryTree(pre,vin);

    s.printTree(root);
}
