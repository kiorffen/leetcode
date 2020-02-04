/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/09
* @brief  
*
**/
#include <cstdio>
#include <vector>
#include <string>

using std::vector;
using std::string;

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            if (strs.size() == 0) {
                return "";
            }

            int min_len = 1 << 31;
            string min_str;
            for (int i = 0; i < strs.size(); i++) {
                if (min_len > strs[i].length()) {
                    min_len = strs[i].length();
                    min_str = strs[i];
                }
            }
            if (min_len == 0) {
                return "";
            }
            string sub_str;
            for (int i = min_len; i >= 0; i--) {
                sub_str = min_str.substr(0, i);
                bool succ = true;
                for (int j = 0; j < strs.size(); j++) {
                    string tmp_str = strs[j].substr(0, i);
                    if (tmp_str != sub_str) {
                        succ = false;
                        break;
                    }
                }
                if (succ == true) {
                    break;
                }
            }

            return sub_str;
        }
};

int main(int argc, char** argv) {
    Solution s;
    vector<string> strs;
    strs.push_back("a");
    strs.push_back("b");
    printf("%s\n", s.longestCommonPrefix(strs).c_str());

    return 0;
}
