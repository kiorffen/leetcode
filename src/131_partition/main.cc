/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/12
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;
        vector<string> one;

        btrace(s, ret, one, 0);

        return ret;
    }

    void btrace(string s, vector<vector<string>> &ret, vector<string> one, int index) {
        if (index == s.size()) {
            ret.push_back(one);
            return;
        }

        for (int i=1; i<=s.size()-index+1;i++) {
            string tmp = s.substr(index, i);
            if (check(tmp)) {
                one.push_back(tmp);
                btrace(s, ret, one, index+i);
                one.pop_back();
            }
        }
    }

    bool check(string s) {
        bool flag = true;
        int i =0;
        int j=s.size()-1;
        while(i<=j) {
            if (s[i]!=s[j]) {
                flag = false;
            }
            i++;
            j--;
        }

        return flag;
    }
};

int main() {
    Solution s;

    vector<vector<string>> ret = s.partition("aabaaccssddasdaeeedsss");
    for (auto v:ret) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
