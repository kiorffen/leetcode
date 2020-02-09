/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/06
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> split(const string& str, const string& pattern) {
        vector<string> res;
        if (str=="") {
            return res;
        }

        string str_tmp  = str + pattern;
        size_t pos = str_tmp.find(pattern);
        size_t pl = pattern.size();
        while (pos!=str_tmp.npos) {
            string tmp = str_tmp.substr(0,pos);
            res.push_back(tmp);
            str_tmp = str_tmp.substr(pos+pl, str_tmp.size() - pos - pl);
            pos = str_tmp.find(pattern);
        }

        return res;
    }

    int compareVersion(string version1, string version2) {
        vector<string> parts1 = split(version1, ".");
        vector<string> parts2 = split(version2, ".");

        vector<int> v1;
        vector<int> v2;

        for (auto s:parts1) {
            v1.push_back(atoi(s.c_str()));
        }
        for (auto s:parts2) {
            v2.push_back(atoi(s.c_str()));
        }

        int len1=v1.size();
        int len2=v2.size();
        if (len1>len2) {
            for (int i=0;i<len1-len2;i++) {
                v2.push_back(0);
            }
        } else if (len1<len2) {
            for (int i=0;i<len2-len1;i++) {
                v1.push_back(0);
            }
        }

        for (int i=0;i<v1.size();i++) {
            if (v1[i] > v2[i]) {
                return 1;
            }
            if (v1[i]<v2[i]) {
                return -1;
            }
        }

        return 0;
    }
};


int main() {
    string version1 = "2.2";
    string version2 = "2.2";

    Solution s;
    int ret = s.compareVersion(version1, version2);

    cout << ret << endl;

    return 0;
}
