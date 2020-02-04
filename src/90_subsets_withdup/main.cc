/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/29
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> one;
        res.push_back(one);

        backtrace(0, nums, one, res);

        return res;
    }

    void backtrace(int start, vector<int>& nums, vector<int> &one, vector<vector<int>> &res) {
        if (start == nums.size()) {
            return;
        }

        for (int i=start; i<nums.size();i++) {
            if (i>start && nums[i]==nums[i-1]) {
                continue;
            }
            one.push_back(nums[i]);
            res.push_back(one);
            backtrace(i+1, nums, one, res);
            one.pop_back();
        }
    }
};

int main() {

    vector<int> nums = {1,2,2};

    Solution s;

    vector<vector<int>> res = s.subsetsWithDup(nums);

    for (auto v:res) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
