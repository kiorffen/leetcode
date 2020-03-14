/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/08
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class NumMatrix {
public:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m>0) {
            int n = matrix[0].size();
            for (int i=0;i<m+1;i++) {
                vector<int> v;
                for (int j=0;j<n+1;j++) {
                    v.push_back(0);
                }
                dp.push_back(v);
            }

            for (int i=0;i<m;i++) {
                for (int j=0;j<n;j++) {
                    dp[i+1][j+1] = dp[i+1][j] + dp[i][j+1] + matrix[i][j] - dp[i][j];
                }
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2+1][col2+1] - dp[row1][col2+1] - dp[row2+1][col1] + dp[row1][col1];
    }
};

int main() {
    //vector<vector<int>> matrix = {{3, 0, 1, 4, 2},{5, 6, 3, 2, 1},{1, 2, 0, 1, 5},{4, 1, 0, 1, 7},{1, 0, 3, 0, 5}};
    vector<vector<int>> matrix = {};

    NumMatrix *obj = new NumMatrix(matrix);

    //int ret1 = obj->sumRegion(2,1,4,3);
    //int ret2 = obj->sumRegion(1,1,2,2);
    //int ret3 = obj->sumRegion(1,2,2,4);

    //cout << ret1 << endl;
    //cout << ret2 << endl;
    //cout << ret3 << endl;


    return 0;
}

