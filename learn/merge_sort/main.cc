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

vector<int> merge(vector<int>& sub1, vector<int>& sub2) { 
    vector<int> res;
    int l1 = sub1.size();
    int l2 = sub2.size();
    int i=0;
    int j=0;
    while (i<l1&&j<l2) {
        if (sub1[i] < sub2[j]) {
            res.push_back(sub1[i]);
            i++;
        } else {
            res.push_back(sub2[j]);
            j++;
        }
    }
    while (i<l1) {
        res.push_back(sub1[i]);
        i++;
    }
    while (j<l2) {
        res.push_back(sub2[j]);
        j++;
    }

    return res;
}

vector<int> merge_sort(vector<int> &nums) {
    vector<int> res;
    int len = nums.size();
    if (len<2) {
        return nums;
    }

    int mid = (len-1)/2;
    vector<int> sub1;
    vector<int> sub2;
    for (int i=0;i<=mid;i++) {
        sub1.push_back(nums[i]);
    }
    for (int j=mid+1;j<len;j++) {
        sub2.push_back(nums[j]);
    }
    vector<int> ret1 = merge_sort(sub1);
    vector<int> ret2 = merge_sort(sub2);

    return merge(ret1, ret2);
}


int main() {
    vector<int> nums = {7,8,12,3,5,78,34,23,566,444,2,3,45};

    if (nums.size()<=1) {
        return 0;
    }
    vector<int> ret = merge_sort(nums);

    for (auto i:ret) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
