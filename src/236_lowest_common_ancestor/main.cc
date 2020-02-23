/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/23
* @brief  
*
**/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    map<TreeNode*,bool> gmap;
    TreeNode* gans;
public:
    TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root,p,q);
        return gans;
    }
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        int mid=0,left=0,right=0;
        if (root==NULL) {
            return false;
        }
        if (root==p||root==q) {
            mid=1;
        }
        if (dfs(root->left,p,q)) {
            left=1;
        }

        if (dfs(root->right,p,q)) {
            right=1;
        }

        if (mid+left+right>=2) {
            gans=root;
        }

        return (mid+left+right) > 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root==NULL) {
            return NULL;
        }

        TreeNode* node=find(root,p,q);

        return node;
    }

    TreeNode* find(TreeNode* node, TreeNode* p, TreeNode* q) {
        bool flag1, flag2;
        auto it1 = gmap.find(node->left);
        if (it1 != gmap.end()) {
            flag1 = it1->second;
        }else{
            flag1=check(node->left,p,q);
            gmap[node->left] =flag1;
        }
        auto it2 = gmap.find(node->right);
        if (it2!=gmap.end()) {
            flag2=it2->second;
        } else {
            flag2=check(node->right,p,q);
            gmap[node->right] = flag2;
        }
        if (!flag1&&!flag2) {
            cout << "return" << endl;
            return node;
        }

        if (flag1) {
            cout << "left" << endl;
            return find(node->left,p,q);
        }

        if (flag2) {
            cout << "left" << endl;
            return find(node->right,p,q);
        }
        return NULL;
    }

    bool check(TreeNode* node, TreeNode* p, TreeNode* q) {
        cout << "node: " << node->val << " p: " << p->val << " q: " << q->val << endl;
        if (node==NULL) {
            return false;
        }

        queue<TreeNode*> qu;
        qu.push(node);
        bool pflag=false, qflag=false;
        int num;
        while (!qu.empty()) {
            num = qu.size();
            for (int i=0;i<num;i++) {
                TreeNode* node = qu.front();
                qu.pop();
                if (node==p) {
                    pflag=true;
                }
                if (node==q) {
                    qflag=true;
                }
                if (node->left!=NULL) {
                    qu.push(node->left);
                }
                if (node->right!=NULL) {
                    qu.push(node->right);
                }
            }
        }

        if (pflag==true&&qflag==true){
            return true;
        }
        return false;
    }
};

int main() {
    Solution s;

    TreeNode *root = new TreeNode(10);
    TreeNode *l11 = new TreeNode(8);
    TreeNode *l12 = new TreeNode(13);
    TreeNode *l21 = new TreeNode(7);
    TreeNode *l22 = new TreeNode(9);
    l11->left=l21;
    l11->right=l22;
    root->left=l11;
    root->right=l12;

    TreeNode*node = s.lowestCommonAncestor1(root,l12,l22);

    cout << node->val << endl;


    return 0;
}
