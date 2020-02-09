/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/09
* @brief  
*
**/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        size_t ls = s.size();
        if (ls<10) {
            return res;
        }

        map<string,int> mm;
        string sstr;
        for (int i=0;i<=s.size()-10;i++) {
            sstr = s.substr(i,10);
            auto it = mm.find(sstr);
            if (it==mm.end()) {
                mm[sstr] = 1;
            } else {
                mm[sstr] = mm[sstr]+1;
            }
        }
        for (auto kv:mm) {
            if (kv.second>1) {
                res.push_back(kv.first);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    string str="AAAAAAAAAAA";
    vector<string> res = s.findRepeatedDnaSequences(str);
    for (auto ss:res) {
        cout << ss << endl;
    }
    return 0;
}
