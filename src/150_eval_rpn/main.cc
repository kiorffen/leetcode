/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/05
* @brief  
*
**/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    int calc(int a,int b, string op) {
        if (op=="+") {
            return a+b;
        } else if (op=="-") {
            return a-b;
        } else if (op=="*") {
            return a*b;
        } else {
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {

        stack<int> st;

        for (auto s:tokens) {
            if (s=="+" || s=="-" || s=="*" || s=="/") {
                int b=st.top();
                st.pop();
                int a=st.top();
                st.pop();
                cout << "a:" << a << " b:" << b<< endl;
                st.push(calc(a,b,s));
            } else {
                int a = atoi(s.c_str());
                st.push(a);
            }
        }

        return st.top();
    }
};

int main() {
    Solution s;

    vector<string> tokens;
    tokens.push_back("4");
    tokens.push_back("13");
    tokens.push_back("5");
    tokens.push_back("/");
    tokens.push_back("+");

    int ret = s.evalRPN(tokens);

    cout << ret << endl;

    return 0;
}
