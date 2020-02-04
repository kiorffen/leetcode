/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/17
* @brief  
*
**/

#include <cstdio>
#include <stack>
#include <string>

using std::string;
using std::stack;

class Solution {
public:
    bool isValid(string s) {
        stack<char> pattern;
        for (char& c:s) {
            switch(c) {
                case '{':
                case '(':
                case '[':
                    pattern.push(c);
                    break;
                case '}':
                    if (pattern.empty() || pattern.top() != '{') {
                        return false;
                    } else {
                        pattern.pop();
                    }
                    break;
                case ')':
                    if (pattern.empty() || pattern.top() != '(') {
                        return false;
                    } else {
                        pattern.pop();
                    }
                    break;
                case ']':
                    if (pattern.empty() || pattern.top() != '[') {
                        return false;
                    } else {
                        pattern.pop();
                    }
                    break;
            }
        }
        return pattern.empty();
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isValid("{}()[]"));
    printf("%d\n", s.isValid("{})[]"));
    printf("%d\n", s.isValid("[{]}"));

    return 0;
}
