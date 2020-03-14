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
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if (len<=0) {
            return 0;
        }
        vector<int> dp(len, 0);
        dp[0]=1;
        int maxlen = 0;
        for (int i=1;i<len;i++) {
            maxlen = 0;
            for (int j=0;j<i;j++) {
                if (nums[i] > nums[j]) {
                    maxlen = max(dp[j],maxlen);
                }
            }
            dp[i] = maxlen+1;
        }

        for (auto i:dp) {
            cout << i << " ";
        }
        cout << endl;

        maxlen = 1;
        for (int i=0;i<len;i++) {
            if (maxlen<dp[i]) {
                maxlen = dp[i];
            }
        }

        return maxlen;
    }
};

int main() {
    Solution s;
    vector<int> nums = {10,9,2,5,3,4};
    //vector<int> nums = {0};
    int ret = s.lengthOfLIS(nums);
    cout << ret << endl;

    return 0;
}
