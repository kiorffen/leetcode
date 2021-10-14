/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/06
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        vector<int> dp(number+1,0);
        if (number==0) {
            return 0;
        }
        
        dp[0]=1;
        
        for (int i=1;i<=number;i++) {
            for (int num=1;num<=2;num++) {
                cout << "i: " << i << " num: " << num << endl;
                if (i-num>=0) {
                    dp[i] += dp[i-num];
                }
                cout << dp[i] << endl;
            }
        }
        
        return dp[number];
    }
};

int main() {
    Solution s;

    int ret = s.rectCover(3);
    cout << ret << endl;

    return 0;
}
