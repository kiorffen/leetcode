/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/17
* @brief  
*
**/

#include <cstdio>
#include <vector>

using std::vector;

class Solution {
public:
    int removeElement(vector<int>& A, int elem) {
        int begin=0;
        for(int i=0;i<A.size();i++) if(A[i]!=elem) A[begin++]=A[i];
        return begin;
    }
};


int main() {
    vector<int> nums;
    nums.push_back(2);

    Solution s;
    int ret = s.removeElement(nums, 3);

    printf("%d\n", ret);

    for (int i = 0; i < nums.size(); i++) {
        printf("%d\n", nums[i]);
    }


    return 0;
}
