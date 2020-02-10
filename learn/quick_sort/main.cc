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

int partition(vector<int>& nums, int left, int right) {
    int pivot = left;
    int index = left+1;

    for (int i=index;i<=right;i++) {
        if (nums[i]<nums[pivot]) {
            swap(nums, i, index);
            index++;
        }
    }

    swap(nums, pivot, index-1);

    return index-1;
}

void quick_sort(vector<int> &nums, int left, int right) {
    if (left>=right) {
        return;
    }

    int p = partition(nums,left,right);
    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;
    cout << "p: " << p << endl;
    quick_sort(nums, p+1,right);
    quick_sort(nums, left,p-1);
}


int main() {
    vector<int> nums = {7,8,12,3,5,78,34,23,566,444,2,3,45};

    if (nums.size()<=1) {
        return 0;
    }
    quick_sort(nums, 0, nums.size()-1);

    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
