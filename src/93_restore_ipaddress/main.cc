/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/29
* @brief  
*
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if (s.size()>12) {
            return res;
        }
        string one;
        backtrace(0,s,0,one,res);

        return res;
    }

    void backtrace(int len, string s, int num, string one,vector<string> &res) {
        if (len==s.size() && num==4) {
                cout << "len: " << len << endl;
            one.pop_back();
            res.push_back(one);
        }

        for (int i= 1;i<=3;i++) {
            if (len+i<=s.size()) { 
                string tmp = s.substr(len,i);
                //cout << "tmp: " << tmp << endl;
                int val = stoi(tmp);
                if (val<= 255 && to_string(val).size()==i) {
                    string old=one;
                    num+=1;
                    one +=tmp+".";
                    backtrace(len+i,s,num,one,res);
                    num-=1;
                    one= old;
                }
            }
        }
    }
};

int main() {

    string s = "010010";

    Solution so;
    vector<string> res = so.restoreIpAddresses(s);
    for (auto s:res) {
        cout << s << endl;
    }

    return 0;
}
