/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/11
* @brief  
*
**/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mp;

        for (auto i:nums) {
            if (mp.find(i) == mp.end()) {
                mp[i]=1;
            } else {
                mp[i]=mp[i]+1;
            }
        }

        for (auto pr:mp) {
            cout << "step1: " << pr.first << " " << pr.second<<endl;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (auto pr:mp) {
            if (pq.size()==k) {
                auto tmp = pq.top();
                cout << "step2: " << tmp.first << " " << tmp.second << endl;
                if (tmp.first < pr.second) {
                    pq.pop();
                    pq.push(make_pair(pr.second, pr.first));
                }
            } else {
                pq.push(make_pair(pr.second, pr.first));
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            auto tmp = pq.top();
            pq.pop();
            result.push_back(tmp.second);
        }

        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    Solution s;

    vector<int> nums = {3,0,1,0};

    vector<int> ret = s.topKFrequent(nums, 1);

    for (auto i:ret) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}
