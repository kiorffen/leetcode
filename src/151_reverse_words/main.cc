/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/05
* @brief  
*
**/

#include <iostream>
#include <stack>

using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string ret;
        stack<string> words;

        string word;
        word.clear();
        for (auto c:s) {
            if (c!=' ') {
                word.push_back(c);
            } else {
                if (!word.empty()) {
                    words.push(word);
                    word.clear();
                    words.push(" ");
                }
            }
        }

        if (!word.empty()) {
            words.push(word);
        }
        if (words.empty()) {
            return "";
        }

        word = words.top();
        if (word==" ") {
            words.pop();
        }

        while (!words.empty()) {
            word = words.top();
            words.pop();
            ret += word;
        }

        return ret;
    }
};

int main() {
    Solution s;

    string str = "nihao    baby test you heart";
    string ret = s.reverseWords(str);

    cout << str << endl;
    cout << ret << endl;

    return 0;
}
