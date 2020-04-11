/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/10
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1,0);

        for (int i=1;i<=num;i++) {
            if (i%2==1) {
                dp[i] = dp[i-1]+1;
            } else {
                dp[i] = dp[i/2];
            }
        }

        return dp;
    }
};

int main() {

    Solution s;

    vector<int> ret = s.countBits(5);
    for (auto i:ret) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
