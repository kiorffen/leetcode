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

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> one;
        int cnt = 0;
        int sum = 0;
        int start = 1;
        btrace(start, cnt,sum,k,n,res,one);

        return res;
    }

    void btrace(int start, int cnt, int sum, int k, int n, vector<vector<int>>& res, vector<int>& one) {
        if (cnt==k&& sum==n) {
            res.push_back(one);
        } 

        for (int i=start;i<=9;i++) {
            one.push_back(i);
            cnt++;
            sum+=i;
            btrace(i+1,cnt,sum,k,n,res,one);
            one.pop_back();
            cnt--;
            sum-=i;
        }

    }
};

int main() {
    Solution s;

    vector<vector<int>> res = s.combinationSum3(3,9);

    for (auto v:res) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
