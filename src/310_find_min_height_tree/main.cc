/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/08
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> degree;
        vector<vector<int>> Graph(n, vector<int>());
        queue<int> qu;

        for (int i=0;i<n;i++) {
            degree.push_back(0);
        }

        for (auto e:edges) {
            Graph[e[0]].push_back(e[1]);
            Graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        for (int i=0;i<n;i++) {
            if (degree[i]==1) {
                qu.push(i);
            }
        }

        int rst=n;
        if (rst==1) {
            ans.push_back(0);
        }

        while (rst!=1&&rst!=2) {
            int len=qu.size();
            rst-=len;
            for (int i=0;i<len;i++) {
                int cur=qu.front();
                qu.pop();
                for (auto v:Graph[cur]) {
                    if (degree[v]>0) {
                        degree[v]--;
                    }
                    if (degree[v]==1) {
                        qu.push(v);
                    }
                }
            }
        }

        while (!qu.empty()) {
            ans.push_back(qu.front());
            qu.pop();
        }

        return ans;
    }
};

int main() {

    vector<vector<int>> edges = {{1,0},{1,2},{1,3}};
    Solution s;
    vector<int> ret = s.findMinHeightTrees(4, edges);
    for (auto i:ret) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
