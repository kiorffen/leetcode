/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/28
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size()==0) {
            return false;
        }

        int left = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right-left)/2;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[mid] == nums[left]) {
                left++;
                continue;
            }

            if (nums[left] < nums[mid]) {
                if (target >=nums[left] && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else{
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid+1;
                } else {
                    right = mid-1;
                }
            }
        }

        return false;
    }
};

int main() {

    vector<int> nums = {2,5,6,0,0,1,2};

    Solution s;
    cout << s.search(nums, 0) << endl;
    cout << s.search(nums, 3) << endl;

    return 0;
}
