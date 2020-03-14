/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/14
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int pivot = nums.size()/2;

        int flag = nums.size()&1;

        vector<int> res;
        if (flag==0) {
            for (int i=pivot-1;i>=0;i--) {
                res.push_back(nums[i]);
                res.push_back(nums[i+pivot]);
            }
        } else {
            for (int i=pivot;i>0;i--) {
                res.push_back(nums[i]);
                res.push_back(nums[i+pivot]);
            }
            res.push_back(nums[0]);
        }

        nums.assign(res.begin(), res.end());

    }
};


int main() {
    vector<int> nums = {1, 5, 1, 1, 6, 4};
    //vector<int> nums = {4,5,5,6};
    //vector<int> nums = {1, 1, 2, 1, 2, 2,1};
    Solution s;

    s.wiggleSort(nums);
    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
