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

using std::sort;
using std::vector;

static bool comp_func(int i, int j) {
    return i < j;
}

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int>& nums) {
            vector<vector<int> > res;
            sort(nums.begin(), nums.end(), comp_func);
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] > 0) {
                    break;
                }
                if (i > 0 && nums[i] == nums[i-1]) {
                    continue;
                }
                int target = 0 - nums[i];
                int l = i + 1;
                int r = nums.size() - 1;
                while (l < r) {
                    if (nums[l] + nums[r] < target) {
                        l++;
                    } else if (nums[l] + nums[r] > target) {
                        r--;
                    } else {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[l]);
                        tmp.push_back(nums[r]);
                        res.push_back(tmp);
                        while (l < r && nums[l+1] == nums[l]) {
                            l++;
                        }
                        while (l < r && nums[r-1] == nums[r]) {
                            r--;
                        }
                        l++;
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
    vector<vector<int> > res;
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    res = s.threeSum(nums);
    for (int i = 0; i < res.size(); i++) {
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }

    return 0;
}
