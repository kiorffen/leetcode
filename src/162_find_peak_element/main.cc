/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/06
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        int mid = 0;
        while (left<right) {
            mid = left+(right-left)/2;
            cout << "mid: " << mid << "left: " << left << "right: " << right << endl;
            if (nums[mid]>nums[mid+1]) {
                right = mid;
            } else {
                left = mid+1;
            }
        }

        return left;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);

    Solution s;
    int ret = s.findPeakElement(nums);

    cout << ret << endl;

    return 0;
}
