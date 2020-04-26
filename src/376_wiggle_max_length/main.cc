/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/26
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();

        if (len<2) {
            return len;
        }

        vector<int> down(len+1,1);
        vector<int> up(len+1, 1);

        for (int i=1;i<len;i++) {
            if (nums[i]>nums[i-1]) {
                up[i] = down[i-1]+1;
                down[i] = down[i-1];
            } else if (nums[i]<nums[i-1]) {
                down[i]=up[i-1]+1;
                up[i] = up[i-1];
            } else {
                down[i] = down[i-1];
                up[i] = up[i-1];
            }
        }

        return max(down[len-1], up[len-1]);
    }
};

int main() {
    Solution s;

    vector<int> nums={2,4,5,7,5,5,7,1,2,3};

    int ret = s.wiggleMaxLength(nums);

    cout << ret << endl;

    return 0;
}
