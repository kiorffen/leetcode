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
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.size() == 0) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }

        int l = 0;
        int r = nums.size() - 1;

        int ret_l = nums.size();
        int ret_r = -1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (ret_l > mid) {
                    ret_l = mid;
                }
            }
            if (nums[mid] >= target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        l = 0;
        r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) {
                if (ret_r <= mid) {
                    ret_r = mid;
                }
            }
            if (nums[mid] <= target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if (ret_l == nums.size()) {
            ret_l = -1;
        }

        res.push_back(ret_l);
        res.push_back(ret_r);
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;

    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    vector<int> res;
    res = s.searchRange(nums, 6);

    printf("%d\n", res[0]);
    printf("%d\n", res[1]);

    return 0;
}
