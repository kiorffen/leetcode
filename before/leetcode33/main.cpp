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
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }

        int l = 0;
        int r = nums.size() - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                return mid;
            } 
            if (nums[mid] < nums[r]) {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (nums[mid] > target && nums[l] <= target) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }

        return -1;
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

    printf("%d\n", s.search(nums, 6));
    printf("%d\n", s.search(nums, 3));

    return 0;
}
