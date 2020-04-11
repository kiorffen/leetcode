/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/10
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) {
            return false;
        }

        int small=INT_MAX;
        int mid=INT_MAX;
        for (int i=0;i<len;i++) {
            if (nums[i]<=small) {
                small = nums[i];
            } else if (nums[i]<=mid) {
                mid=nums[i];
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2,1,3,1,5};

    bool flag = s.increasingTriplet(nums);
    cout << flag << endl;

    return 0;
}
