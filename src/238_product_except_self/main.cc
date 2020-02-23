/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/23
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        if (len==0) {
            return res;
        }
        if (len==1) {
            res.push_back(nums[0]);
            return res;
        }
        vector<int> a(len,0);
        vector<int> b(len,0);
        for (auto i:nums) {
            cout << i << " ";
        }
        cout << endl;
        cout << nums[0] << endl;

        a[0]=nums[0];
        b[len-1] = nums[len-1];

        for (int i=1;i<len;i++) {
            a[i] = a[i-1]*nums[i];
        }

        for (auto i:a) {
            cout << i << " ";
        }
        cout << endl;

        for (int i=len-2;i>=0;i--){
            b[i] = b[i+1]*nums[i];
        } 
        for (auto i:b) {
            cout << i << " ";
        }
        cout << endl;

        res.push_back(b[1]);
        for (int i=1;i<len-1;i++) {
            res.push_back(a[i-1]*b[i+1]);
        }
        res.push_back(a[len-2]);

        return res;
    }
};

int main() {
    Solution s;

    vector<int> nums={1};

    vector<int> res = s.productExceptSelf(nums);

    for (auto i:res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
