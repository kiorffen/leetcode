/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/12
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class UnionFind {
public:
    UnionFind(int totalNodes) {
        for (int i=0; i<totalNodes;i++) {
            parents.push_back(i);
        }
    }

    void union_node(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);

        if (root1 != root2) {
            parents[root2] = root1;
        }
    }

    int find(int node) {
        while(parents[node]!=node) {
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        
        return node;
    }

    bool is_connected(int node1, int node2) {
        return find(node1) == find(node2);
    }

private:
    vector<int> parents;

};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m==0) {
            return;
        }
        int n = board[0].size();

        UnionFind uf(m*n+1);
        int dummy_node = m*n;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (board[i][j]=='O') {
                    if (i==0||j==0||i==m-1||j==n-1) {
                        uf.union_node(node(i,j,n), dummy_node);
                    } else {
                        if (i>0 && board[i-1][j]=='O') {
                            //uf.union_node(node(i,j,n),node(i-1,j,n));
                            uf.union_node(node(i-1,j,n),node(i,j,n));
                        }
                        if (j>0 && board[i][j-1]=='O') {
                            //uf.union_node(node(i,j, n), node(i,j-1,n));
                            uf.union_node(node(i,j-1,n),node(i,j,n));
                        }
                        if (i<m-1 && board[i+1][j]=='O') {
                            //uf.union_node(node(i,j,n), node(i+1,j,n));
                            uf.union_node(node(i+1,j,n),node(i,j,n));
                        }
                        if (j<n-1 && board[i][j+1]=='O') {
                            //uf.union_node(node(i,j,n), node(i,j+1,n));
                            uf.union_node(node(i,j+1,n),node(i,j,n));
                        }
                    }
                }
            }
        }

        for (int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if (uf.is_connected(node(i,j,n), dummy_node)) {
                    board[i][j] = 'O';
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    int node(int i,int j,int n) {
        return i*n+j;
    }
};

int main() {
    Solution s;

    vector<vector<char>> board = {{'X','X','X','X'},{'X', 'O', 'O', 'X'},{'X','X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};

    s.solve(board);

    for (auto v:board) {
        for (auto i:v) {
            cout << i << "";
        }
        cout << endl;
    }

    return 0;
}
