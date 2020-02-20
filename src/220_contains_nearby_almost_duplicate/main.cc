/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/18
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> records;

        for (int i=0;i<nums.size();i++) {
            auto s = records.lower_bound((double)nums[i]-t);
            if (s!=records.end() && *s <= (double)nums[i]+t) {
                return true;
            }

            records.insert(nums[i]);

            if (records.size()==k+1) {
                records.erase(nums[i-k]);
            }
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1,2,3,1};
    Solution s;

    cout << s.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;

    return 0;
}
