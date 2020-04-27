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

#include <stack>
#include <iostream>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int tmp = stack1.top();
                stack1.pop();
                stack2.push(tmp);
            }
        }
        int data = stack2.top();
        stack2.pop();
        return data;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while (!stack1.empty()) {
            int tmp=stack1.top();
            stack1.pop();
            stack2.push(tmp);
        }
        int data = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            int tmp=stack2.top();
            stack2.pop();
            stack1.push(tmp);
        }

        return data;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
}
