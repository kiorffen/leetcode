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

void shell_sort(vector<int> &nums) {
    int len = nums.size();
    int current;

    for (int gap=len/2;gap>0;gap=gap/2) {
        for (int i=gap;i<len;i++) {
            current = nums[i];
            int j = i-gap;
            while (j>=0 && current < nums[j]) {
                nums[j+gap] = nums[j];
                j=j-gap;
            }
            nums[j+gap] = current;
        }
    }
}

int main() {
    vector<int> nums = {7,8,12,3,5,78,34,23,566,444,2,3,45};

    if (nums.size()<=1) {
        return 0;
    }
    shell_sort(nums);

    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
