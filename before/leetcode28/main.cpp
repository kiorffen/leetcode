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
#include <string>

using std::string;

class Solution {
public:
    int strStr(string haystack, string needle) {   
        if (haystack.length() < needle.length()) {
            return -1;
        }
        int m = haystack.length();
        int n = needle.length();
        for (int i = 0; i <= m - n; i++) {
            int j = 0;
            for (j = 0; j < n; j++) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
            }
            if (j == n) {
                return i;
            }
        }

        return -1;
    }
};


int main() {
    Solution s;
    printf("%d\n", s.strStr("aaaaaaa", "aab"));

    return 0;
}
