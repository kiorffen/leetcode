/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/23
* @brief  
*
**/

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
private:
    map<pair<int,int>, vector<int>> m;
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res = ways(input, 0, input.size());
        return res;
    }

    vector<int> ways(string input, int left, int right) {
        if (m.find(make_pair(left, right))!=m.end()) {
            return m[make_pair(left, right)];
        }

        vector<int> res;
        for (int i=left;i<right;++i) {
            char c = input[i];
            if (c=='+' || c=='-' || c=='*') {
                vector<int> l = ways(input, left,i);
                vector<int> r = ways(input, i+1, right);

                for (auto il :l) {
                    for (auto ir:r) {
                        res.push_back(ops(c,il,ir));
                    }
                }
            }
        }
        if (res.size()==0) {
            res.push_back(stoi(input.substr(left,right-left)));
        }
        m[make_pair(left,right)]=res;

        return res;
    }

    int ops(char op, int l, int r) {
        switch(op) {
        case '+': return l+r;
        case '-': return l-r;
        case '*': return l*r;
        }

        return 0;
    }
};

int main() {
    string str = "2*3-4*5";

    Solution s;
    vector<int> res = s.diffWaysToCompute(str);

    for (auto i:res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
