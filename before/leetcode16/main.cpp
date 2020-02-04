/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2018/03/09
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <math.h>

using std::sort;
using std::vector;

static bool comp_func(int i, int j) {
    return i < j;
}

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end(), comp_func);
            int res = nums[0] + nums[1] + nums[2];
            int diff = abs(res - target);
            for (int i = 0; i < nums.size() - 2; i++) {
                int l = i + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    int sum = nums[i] + nums[l] + nums[r];
                    if (diff > abs(sum - target)) {
                        diff = abs(sum - target);
                        res = sum;
                    }
                    if (sum < target) {
                        l++;
                    } else {
                        r--;
                    }
                }
            }

            return res;
        }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-3);
    int res = s.threeSumClosest(nums, 1);
    printf("res%d\n", res);


    return 0;
}
