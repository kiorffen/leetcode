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
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() (const pair<int, pair<int,int>>& a, const pair<int, pair<int,int>>& b) {
            return a.first+a.second.first > b.first+b.second.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        int len1=nums1.size();
        int len2=nums2.size();
        if (len1==0||len2==0) {
            return ans;
        }
        cout << len1 << " " << len2 << " " << k <<endl;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp> pq;
        for (int i=0;i<len1;i++) {
            pair<int,pair<int,int>> t(nums1[i], pair<int,int>(nums2[0],0));
            pq.push(t);
        }

        for (int i=0;i<k&&!pq.empty();i++) {
            pair<int,pair<int,int>> t=pq.top();
            pq.pop();
            vector<int> s={t.first,t.second.first};
            cout << "i: " << i << " f: " << t.first << " s: " << t.second.first << endl;;
            ans.push_back(s);
            if (t.second.second < len2-1) {
                t.second.second++;
                t.second.first = nums2[t.second.second];
                pq.push(t);
            }
        }

        return ans;
    }
};

int main() {

    Solution s;
    vector<int> nums1={1,7,11};
    vector<int> nums2={2,4,6};
    vector<vector<int>> ret = s.kSmallestPairs(nums1,nums2,9);

    for (auto v:ret) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
