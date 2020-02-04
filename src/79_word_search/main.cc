/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/28
* @brief  
*
**/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) {
            return false;
        }

        int m = board.size();
        int n = board[0].size();

        vector<vector<bool>> mark(m,vector<bool>(n));

        for (int i = 0; i<board.size();i++) {
            for (int j=0; j<board[0].size();j++) {
                if (search_word(i,j,0,mark,board,word)){
                    return true;
                }
            }
        }

        return false;
    }

    bool search_word(int i, int j, int index, vector<vector<bool>> &mark, vector<vector<char>> &board, string word) {
        if (index == word.size()-1) {
            return word[index] == board[i][j];
        }

        if (board[i][j] == word[index]) {
            mark[i][j] = true;
            for (auto v:directions) {
                int i_new = i+v[0];
                int j_new = j+v[1];

                if (i_new>=0 && i_new<board.size() && j_new>=0 && j_new< board[0].size()&&!mark[i_new][j_new]) {
                    if (search_word(i_new, j_new, index+1, mark, board, word)) {
                        return true;
                    }
                }

            }
            mark[i][j]=false;
        }

        return false;
    }
};

int main() {

    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word="ABCCED";
    string word1="SEE";
    string word2="ABCB";

    Solution s;
    cout << s.exist(board, word) << endl;
    cout << s.exist(board, word1) << endl;
    cout << s.exist(board, word2) << endl;

    return 0;
}
