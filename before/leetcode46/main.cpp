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

using std::vector;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        vector<int> curr;
        vector<vector<int> > res;
        permute(nums, curr, res);
        return res;
    }

    void permute(vector<int> nums, vector<int> curr, vector<vector<int> >& res) {
        if(nums.size() == 1) {
            curr.push_back(nums[0]);
            res.push_back(curr);
        }
        for (int i = 0; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
            vector<int> temp;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] != nums[i]) {
                    temp.push_back(nums[j]);
                }
            }
            permute(temp, curr, res);
            curr.pop_back();
        }

    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int> > res = s.permute(nums);
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }

    return 0;
}
