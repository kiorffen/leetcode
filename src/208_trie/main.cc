/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/12
* @brief  
*
**/

#include <iostream>
#include <string>

using namespace std;

class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    /** Initialize your data structure here. */
    Trie() {
        isEnd = false;
        for (int i=0;i<26;i++) {
            next[i] = NULL;
        }
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c:word) {
            if (node->next[c-'a']==NULL) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c:word) {
            if (node->next[c-'a']==NULL) {
                return false;
            }
            node = node->next[c-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c:prefix) {
            if (node->next[c-'a']==NULL) {
                return false;
            }
            node = node->next[c-'a'];
        }

        return true;
    }
};

int main() {
    Trie* trie = new Trie();

    trie->insert("apple");
    cout << trie->search("apple")<<endl;
    cout << trie->search("app")<<endl;
    cout << trie->startsWith("app")<<endl;
    trie->insert("app");
    cout << trie->search("app")<<endl;

    return 0;
}

