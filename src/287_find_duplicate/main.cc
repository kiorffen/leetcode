/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/06
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for (int i=1;i<nums.size();i++) {
            if (nums[i]==nums[i-1]) {
                return nums[i];
            }
        }

        return 0;
    }
    int findDuplicate1(vector<int>& nums) {
        int slow=0;
        int fast=0;
        while (1) {
            slow=nums[slow];
            fast=nums[nums[fast]];
            cout << "slow: " << slow << " fast: " << fast << endl;
            if (slow==fast) {
                break;
            }
        }
        int find = 0;
        while (1) {
            find = nums[find];
            slow = nums[slow];
            cout << "slow: " << slow << " find: " << find << endl;
            if (find==slow) {
                break;
            }
        }
        
        return slow;
    }
    int findDuplicate2(vector<int>& nums) {
        int left = 1;
        int right = nums.size()-1;
        int pivot = 0;
        int cnt = 0;
        int i=0;
        while (left<right) {
            pivot = left + (right-left)/2;
            cnt = 0;
            for (i=0;i<nums.size();i++) {
                if (nums[i]<=pivot) {
                    cnt++;
                }
            }
            cout << "left: " << left << " right: " << right << " pivot:" << pivot << " cnt: " << cnt << endl;
                if (cnt>pivot) {
                    right = pivot;
                } else {
                    left = pivot+1;
                }
        } 

        return left;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,4,2,2 };
    int ret = s.findDuplicate2(nums);
    cout << ret << endl;
}
