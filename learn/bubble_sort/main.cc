/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/10
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void bubble_sort(vector<int> &nums) {
    int len = nums.size();
    for (int i=0;i<len;i++) {
        for (int j=0;j<len-i-1;j++) {
            if (nums[j]>nums[j+1]) {
                swap(nums, j, j+1);
            }
        }
    }
}

int main() {
    vector<int> nums = {7,8,12,3,5,78,34,23,566,444,2,3,45};

    if (nums.size()<=1) {
        return 0;
    }
    bubble_sort(nums);

    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
