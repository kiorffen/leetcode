/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/17
* @brief  
*
**/

#include <iostream>

using namespace std;


struct Trie{
    bool isEnd;
    Trie* next[26];

    Trie() {
        isEnd = false;
        for (int i=0;i<26;i++) {
            next[i] = NULL;
        }
    }
};

class WordDictionary {
private:
    Trie* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* node = root;
        for (auto c:word) {
            //cout << "insert: " << c << endl;
            if (node->next[c-'a']==NULL) {
                node->next[c-'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int index = 0;
        Trie* node = root;
        return dfs(word, index, node);
    }

    bool dfs(string word, int index, Trie* node) {
        if (index==word.size()) {
            if (node->isEnd) {
                return true;
            } else {
                return false;
            }
        }
        char c= word[index];
        //cout << "search: " << c << endl;
        if (c!='.') {
            if (node->next[c-'a']!=NULL) {
                return dfs(word, index+1, node->next[c-'a']);
            } else {
                return false;
            }
        } else {
            for (int i=0; i<26;i++) {
                if (node->next[i]!=NULL&&dfs(word, index+1, node->next[i])) {
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    WordDictionary* obj = new WordDictionary();
    obj->addWord("add");
    cout << obj->search(".at") << endl;
    obj->addWord("bat");
    cout << obj->search(".at") << endl;

    cout <<false<< endl;
    cout <<true<< endl;

    return 0;
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
