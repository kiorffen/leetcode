/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/01/18
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int sum = 0;
        int cur = 0;
        for (int i = 0;i<n;i++) {
            sum+=gas[i] - cost[i];
            cur+=gas[i] - cost[i];
            if (cur < 0) {
                start = i+1;
                cur = 0;
            }
        }

        if (sum>=0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution s;
    vector<int> gas = {1,2,3,4,5};
    vector<int> cost = {3,4,5,1,2};
    int ret = s.canCompleteCircuit(gas, cost);
    cout << ret << endl;
    return 0;
}
