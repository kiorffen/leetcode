/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/09
* @brief  
*
**/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;

        int m = grid.size();
        if (m==0) {
            return res;
        }
        int n = grid[0].size();
        if (n==0) {
            return res;
        }

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                if (grid[i][j]=='1') {
                    res++;
                    dfs(grid,i,j);
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        grid[i][j]='0';
        if (i-1>=0&&grid[i-1][j]=='1') {
            dfs(grid,i-1,j);
        }
        if (i+1<m&&grid[i+1][j]=='1') {
            dfs(grid,i+1,j);
        }
        if (j-1>=0&&grid[i][j-1]=='1') {
            dfs(grid,i,j-1);
        }
        if (j+1<n&&grid[i][j+1]=='1') {
            dfs(grid,i,j+1);
        }
    }
};

int main() {
    Solution s;

    vector<vector<char>> grid={{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};

    int ret = s.numIslands(grid);

    cout << ret<<endl;
}
