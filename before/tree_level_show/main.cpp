/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/10
* @brief  
*
**/

struct Node {
     Node*left, *right;
     char val; 
};
 
void PrintTree(const Node* root)
{
    Stack s1, s2;
    s1.push(root);
    while(s1.size() > 0) {
        int len1 = s1.size();
        while(len1 > 0) {
            Node* node = s1.pop();
            cout <<node->val;
            if (node->left != NULL) {
                s2.push(node->left);
            }
            if (node->right != NULL) {
                s2.push(node->right);
            }
            len1--;
        }
        cout << endl;
        int len2 = s2.size();
        while(len2 > 0) {
            Node* node = s2.pop();
            cout << node->val;
            if (node->right != NULL) {
                s1.push(node->right);
            }
            if (node->left != NULL) {
                s1.push(node->left);
            }
            len2--;
        }
        cout << endl;
        
    }
}
