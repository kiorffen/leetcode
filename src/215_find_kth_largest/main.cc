/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/17
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> vheap;
        for (int i=0;i<k;i++) {
            vheap.push_back(nums[i]);
        }

        make_heap(vheap.begin(), vheap.end(), greater<int>());
        
        int top = 0;
        pop_heap(vheap.begin(), vheap.end(), greater<int>());
        top = vheap.back();
        for (int i=k;i<nums.size();i++) {
            if (nums[i]>top) {
                vheap.pop_back();
                vheap.push_back(nums[i]);
                make_heap(vheap.begin(), vheap.end(), greater<int>());
                pop_heap(vheap.begin(), vheap.end(), greater<int>());
                top = vheap.back();
            }
        }

        return top;
    }

    int findKthLargest1(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k);
    }

    int quickSelect(vector<int>& nums, int left, int right, int k) {
        if (left==right) {
            return nums[left];
        }

        int p_index = partition(nums, left, right);
        cout << "p_index: " << p_index << endl;
        for (auto i:nums) {
            cout << i <<" ";
        }
        cout << endl;

        if (p_index+1 == k) {
            return nums[p_index];
        } else if (p_index+1>k){
            return quickSelect(nums, left, p_index-1, k);
        } else {
            return quickSelect(nums, p_index+1, right, k);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivot = left;
        int index = left+1;

        for (int i=index;i<=right;i++) {
            if (nums[i]>nums[pivot]) {
                swap(nums, index, i);
                index++;
            }
        }

        swap(nums, pivot, index-1);
        return index-1;
    }

    void swap(vector<int>& nums, int a, int b) {
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
};

int main() {

    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    Solution s;
    
    int ret = s.findKthLargest1(nums, 4);
    cout << "ret: " << ret << endl;

    return 0;
}
