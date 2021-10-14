/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/14
* @brief  
*
**/
#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        vector<string> res;
        if (str.size()==0) {
            return res;
        }
        
        string one;
        set<int> pos;
        cout << "call dfs" << endl;
        dfs(str,one,pos,res);
        return res;
    }
    
    void dfs(string str, string one, set<int>& pos,vector<string>& res) {
        if (one.size()==str.size()) {
            //cout << one << endl;
            res.push_back(one);
            return;
        }
        
        for (int i=0;i<str.size();i++) {
            if (pos.find(i)==pos.end()) {
                one.push_back(str[i]);
                pos.insert(i);
                dfs(str,one,pos,res);
                one.pop_back();
                pos.erase(i);
            }
        }
    }
};

int main() {
    Solution s;

    vector<string> res = s.Permutation("aa");
    for (auto s:res) {
        cout << s << endl;
    }

    return 0;
}
