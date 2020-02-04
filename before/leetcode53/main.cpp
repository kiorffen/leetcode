/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/19
* @brief  
*
**/

#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::max;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int sum = 0;
        int max_sum = -(1<<31);
        for (int i = 0; i < nums.size(); i++) {
            printf("sum:%d\n", sum);
            printf("max_sum:%d\n", max_sum);
            sum = max(nums[i], sum + nums[i]);
            max_sum = max(max_sum, sum);
        }
        return max_sum;
    }
};


int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-5);
    nums.push_back(4);

    printf("%d\n", s.maxSubArray(nums));

    return 0;
}
