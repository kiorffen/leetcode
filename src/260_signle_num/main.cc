/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/24
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int, int> nums_cnt;
        vector<int> res;

        for (auto num:nums) {
            if (nums_cnt.find(num)==nums_cnt.end()) {
                nums_cnt[num]=1;
            } else {
                nums_cnt[num]+=1;
            }
        }

        for (auto kv:nums_cnt) {
            if (kv.second==1) {
                res.push_back(kv.first);
            }
        }

        return res;
    }
};


int main() {
    Solution s;

    vector<int> nums = {1,2,1,3,2,5};

    vector<int> res = s.singleNumber(nums);
    for (auto i:res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
