/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/12
* @brief  
*
**/

#include <iostream>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen_n3(int s, vector<int>& nums) {
        int ret = INT_MAX;
        int len = nums.size();

        int sum = 0;
        for (int i=0;i<len;i++) {
            for (int j=i;j<len;j++) {
                sum = 0;
                for (int k=i;k<=j;k++) {
                    sum+=nums[k];
                }
                if (sum>=s) {
                    ret = min(ret,j-i+1);
                    break;
                }
            }
        }

        return ret;
    }
    int minSubArrayLen_n2(int s, vector<int>& nums) {
        int ret = INT_MAX;
        int len = nums.size();

        vector<int> sums(len,0);
        sums[0] = nums[0];
        for (int i=1;i<len;i++) {
            sums[i] = sums[i-1] + nums[i];
        }

        int sum = 0;
        for (int i=0;i<len;i++) {
            for (int j=i;j<len;j++) {
                sum = sums[j]-sums[i]+nums[i];
                if (sum>=s) {
                    ret = min(ret,j-i+1);
                    break;
                }
            }
        }

        return ret;
    }
    int minSubArrayLen_n(int s, vector<int>& nums) {
        int begin = 0;
        int ret = INT_MAX;
        int len = nums.size();

        int i = 0;
        int sum = 0;
        while (i<len) {
            if (sum + nums[i] < s) {
                sum += nums[i];
                i++;
            } else {
                if (i-begin<ret) {
                    ret = i-begin+1;
                }
                sum = sum-nums[begin];
                ++begin;
            }
        }

        return ret==INT_MAX?0:ret;
    }
};

int main() {
    Solution s;

    vector<int> nums = {2,3,1,2,4,3};
    int ret = s.minSubArrayLen_n(7,nums);
    cout << ret << endl;

    return 0;
}
