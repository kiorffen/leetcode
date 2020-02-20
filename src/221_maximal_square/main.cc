/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/18
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mmin(int a, int b, int c) {
        return min(min(a,b),c);
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m==0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));


        int max = 0;
        for (int i=1;i<=m;i++) {
            for (int j=1;j<=n;j++) {
                if (matrix[i-1][j-1]=='1') {
                    dp[i][j] = mmin(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
                    if (max<dp[i][j]) {
                        max = dp[i][j];
                    }
                }
            }
        }

        return max*max;
    }
};

int main() {
    vector<vector<char>> matrix = {{'1','1','0','1','1'},{'1','1','1','0','1'},{'1','1','1','1','1'}};

    Solution s;

    int ret = s.maximalSquare(matrix);

    cout << "ret: " << ret << endl;
    cout << s.mmin(0,0,1) << endl;
    cout << s.mmin(4,2,3) << endl;
    cout << s.mmin(4,7,3) << endl;

    return 0;
}
