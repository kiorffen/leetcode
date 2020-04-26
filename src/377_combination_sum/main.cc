/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/26
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int len = nums.size();
        vector<unsigned int> dp(target+1,0);

        dp[0]=1;
        for (int i=1;i<=target;i++) {
            for (auto num:nums) {
                if (num<=i) {
                    dp[i] += dp[i-num];
                }
            }
        }

        return dp[target];
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3};
    int ret = s.combinationSum4(nums,4);
    cout << ret << endl;


    return 0;
}
