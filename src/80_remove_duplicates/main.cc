/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/28
* @brief  
*
**/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size()<=2) {
            return nums.size();
        }

        int fast = 2;
        int slow = 1;

        while (fast < nums.size()) {
            if (nums[fast] != nums[slow-1]) {
                slow++;
                nums[slow] = nums[fast];
                fast++;
            } else {
                fast++;
            }
        }

        return slow+1;
    }
};

int main() {
    vector<int> nums = {1,1,1,2,2,3};

    Solution s;
    cout << s.removeDuplicates(nums) << endl;

    return 0;
}
