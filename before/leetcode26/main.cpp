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
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int num = nums[0];
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == num) {
                continue;
            } else {
                count+=1;
                num = nums[i];
                nums[count-1] = num;
            }
        }

        return count;
    }
};

int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(3);
    nums.push_back(4);

    Solution s;
    printf("%d\n", s.removeDuplicates(nums));
    for (int i = 0; i < nums.size(); i++) {
        printf("item:%d\n",nums[i]);
    }

    return 0;
}

