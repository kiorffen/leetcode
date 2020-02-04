/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/05
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int w_len = beginWord.size();
        map<string, vector<string>> comp_map;

        for (auto w:wordList) {
            for (int i=0; i<w_len; i++) {
                string temp =w;
                temp[i] = '*';
                comp_map[temp].push_back(w);
            }
        }

        for (auto item:comp_map) {
            cout <<"pattern: " << item.first << endl;
            for (auto i:item.second) {
                cout <<i<<" ";
            }
            cout << endl;
        }

        queue<string> q;
        q.push(beginWord);
        map<string,bool> visited;
        visited[beginWord] = true;

        int level = 0;
        while (!q.empty()) {
            level++;
            int size_q=q.size();
            for (int j=0;j<size_q;j++) {
                string cur = q.front();
                q.pop();
                for (int i=0; i< w_len;i++) {
                    string temp = cur;
                    temp[i]='*';
                    cout << "cur: " << temp << endl;
                    vector<string> word_list = comp_map[temp];
                    for (auto w:word_list) {
                        //cout << "w: " << w << " ";
                        if (w==endWord) {
                            level+=1;
                            return level;
                        } else {
                            auto it = visited.find(w);
                            if (it == visited.end()) {
                                cout << "w: " << w << " ";
                                q.push(w);
                                visited[w] = true;
                            } else {
                                continue;
                            }
                        }
                    }
                    cout << endl;
                }
            }
            cout << "level: "<<level<<endl;
        }

        return 0;
    }
};

int main() {
    Solution s;

    //vector<string> dict = {"hot","dot","dog","lot","log","cog"};
    //string beginWord = "hit";
    //string endWord = "cog";
    vector<string> dict = {"a","b","c"};
    string beginWord = "a";
    string endWord = "c";

    int level = s.ladderLength(beginWord, endWord, dict);

    cout << level << endl;

    return 0;
}
