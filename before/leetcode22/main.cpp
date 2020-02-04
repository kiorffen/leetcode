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
#include <vector>
#include <string>

using std::string;
using std::vector;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = "";
        generateParenthesis(n, n, s, res); 
        return res;
    }

    void generateParenthesis(int left, int right, string s, vector<string>& res) {
        if (left > right) {
            return;
        }
        if (left == 0 && right == 0) {
            res.push_back(s);
        }

        if (left > 0) {
            generateParenthesis(left-1, right, s+'(', res);
        }
        if (right > 0) {
            generateParenthesis(left, right-1, s+')', res);
        }
    }
};

int main() {
    Solution s;
    vector<string> res;
    res = s.generateParenthesis(3);

    printf("%d\n", res.size());

    for (string& s:res) {
        printf("%s\n", s.c_str());
    }

    return 0;
}
