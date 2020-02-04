/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/18
* @brief  
*
**/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        map<string,bool> md;
        for (auto w:wordDict) {
            dict.insert(w);
        }

        return btrace(s,dict,md, 0);
    }

    bool btrace(string s, set<string>& dict,map<string,bool>& md, int start) {
        if (start == s.size()) {
            return true;
        }

        string tmp = s.substr(start, s.size()-start);
        if (md.find(tmp) != md.end()) {
            return md[tmp];
        }

        for (int i=1; i<=s.size()-start;i++) {
            string temp = s.substr(start, i);
            if (dict.find(temp) != dict.end()) {
                cout << "temp: " << temp <<endl;
                if (btrace(s, dict, md, start+i)) {
                    md[tmp] = true;
                    return true;
                }
            }
        }
        md[tmp] = false;

        return false;
    }
};

int main() {
    Solution s;
    //string str = "leetcode";
    //vector<string> dict = {"leet", "code"};
    //bool ret = s.wordBreak(str, dict);
    //cout << ret << endl;
    //cout << true << endl;
    //cout << false << endl;

    string str = "catsandog";
    vector<string> dict = {"cats", "dog", "sand", "and", "cat"};
    bool ret = s.wordBreak(str, dict);
    cout << ret << endl;

    return 0;
}
