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
class Solution {
public:
    int jumpFloorII(int number) {
        int kinds = 0;
        map<int, int> mp;
        
        kinds = dfs(number, mp);
        
        return kinds;
    }
    
    int dfs(int number, map<int,int>& mp) {
        if (number==0) {
            return 1;
        }
        if (mp.find(number)!=mp.end()) {
            return mp[number];
        }
        
        int kinds = 0;
        for (int i=1;i<=number;i++) {
            if (number-i>=0) {
                kinds += dfs(number -i, mp);
            }
        }
        
        mp[number] = kinds;
        return kinds;
    }

};
class Solution {
public:
    int jumpFloorII(int number) {
        vector<int> dp(number+1, 0);
        dp[0]=1;
        
        for (int i=0;i<=number;i++) {
            for (int num=1;num<=number;num++) {
                if (i-num>=0) {
                    dp[i] += dp[i-num];
                }
            }
        }
        
        return dp[number];
    }
    
};
