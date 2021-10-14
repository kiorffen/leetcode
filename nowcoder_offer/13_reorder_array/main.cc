/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/06
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        if (array.size()==0 || array.size()==1) {
            return;
        }
        vector<int> odds;
        vector<int> evens;
        
        for (auto i:array) {
            if (i%2==1) {
                odds.push_back(i);
            } else {
                evens.push_back(i);
            }
        }
        
        array.clear();
        for (auto i:odds) {
            array.push_back(i);
        }
        for (auto i:evens) {
            array.push_back(i);
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,2,3,4,5,6};
    
    s.reOrderArray(nums);
    for (auto i:nums) {
        cout << i << " ";
    }
    cout << endl;
}
