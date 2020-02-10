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

void selection_sort(vector<int> &nums) {
    int len = nums.size();
    int maxIndex;
    for (int i=0;i<len-1;i++) {
        maxIndex = i;
        for (int j=i+1;j<len;j++) {
            if (nums[j]>nums[maxIndex]) {
                maxIndex = j;
            }
        }
        swap(nums, i, maxIndex);
    }
}

int main() {
    vector<int> nums = {7,8,12,3,5,78,34,23,566,444,2,3,45};

    if (nums.size()<=1) {
        return 0;
    }
    selection_sort(nums);

    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
