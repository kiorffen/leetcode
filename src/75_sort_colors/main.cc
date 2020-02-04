/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/15
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0;
        int p2 = nums.size()-1;
        int cur = 0;

        while(cur <= p2) {
            //for (auto i:nums) {
            //    cout << i << " ";
            //}
            cout << endl;
            if (nums[cur]==0){
                swap(nums[p0],nums[cur]);
                p0++;
                cur++;
            } else if (nums[cur]==2) {
                swap(nums[cur], nums[p2]);
                p2--;
            } else {
                cur++;
            }
        }
    }
};

bool comp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> a = {1,0,2,0,1,1,2,2,0,2,2,1};
    for (auto i:a) {
        cout << i << " ";
    }
    cout << endl;

    //Solution s;
    //s.sortColors(a);
    
    sort(a.begin(), a.end(), comp);

    for (auto i:a) {
        cout << i << " ";
    }
    cout << endl;
}
