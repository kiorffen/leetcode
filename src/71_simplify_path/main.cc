/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/15
* @brief  
*
**/

#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::reverse;

class Solution {
public:
    string simplifyPath(string path) {        
        path += "/";
        stack<string> pos;
        string dir;

        for (auto c : path) {
            if (c=='/') {
                if (dir==".." && !pos.empty()) {
                    pos.pop();
                } else if (dir != ".." && dir != "." && !dir.empty()) {
                    pos.push(dir);
                }

                dir.clear();
            } else {
                dir += c;
            }
        }

        string res;

        while(!pos.empty()) {
            string t = pos.top();
            pos.pop();
            res+=string(t.rbegin(), t.rend()) + "/";
        }
        reverse(res.begin(), res.end());
        if (res.empty()) return "/";
        return res;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("../../help/a/../b/./c/") << endl;
}
