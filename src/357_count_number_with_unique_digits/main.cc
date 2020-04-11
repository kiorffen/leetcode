/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/11
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n==0) {
            return 1;
        }

        vector<int> dp(n+2);

        dp[0]=0;
        dp[1]=10;
        dp[2]=91;

        for (int i=3;i<=n;i++) {
            dp[i] = co(i-1,10) + dp[i-1] - co(i-2,9);
        }

        return dp[n];
    }

    int co(int i,int a) {
        if (i==0) {
            return a;
        }
        return a*co(i-1,a-1);
    }
};

int main() {
    Solution s;

    int ret = s.countNumbersWithUniqueDigits(3);
    cout << ret << endl;

    return 0;
}
