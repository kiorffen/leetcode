/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/05
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;

        int min = nums[0];
        int mid = 0;

        if (nums[right]> nums[left]) {
            return nums[left];
        } 
        while (left <right) {
            int mid = left + (right-left)/2;
            if (nums[mid]>nums[mid+1]) {
                return nums[mid+1];
            }
            if (nums[mid]<nums[mid-1]) {
                return nums[mid];
            }
            if (nums[mid] < nums[right]) {
                cout << "step1" << endl;
                right = mid - 1;
            } else if (nums[mid] > nums[left]){
                cout << "step2" << endl;
                left = mid + 1;
            }
            cout << "mid:" << mid << endl;
        }

        return min;
    }
};

int main() {
    Solution s;

    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);

    int ret = s.findMin(nums);

    cout << ret << endl;

    return 0;
}
