/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/06
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numSquares(int n) {

        vector<int> dp(n+1,0);

        for (int i=1;i<=n;i++) {
            dp[i]=i;
            for (int j=1; i-j*j>=0;j++) {
                dp[i] = min(dp[i], dp[i-j*j]+1);
            }
        }

        return dp[n];

    }
};

int main() {
    Solution s;

    int ret = s.numSquares(13);
    cout << ret << endl;

    return 0;
}
