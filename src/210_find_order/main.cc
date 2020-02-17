/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/17
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indgrees(numCourses);
        vector<vector<int>> ajac(numCourses, vector<int>());

        for (auto v:prerequisites) {
            indgrees[v[0]]++;
            ajac[v[1]].push_back(v[0]);
        }

        queue<int> qu;
        for (int i=0;i<numCourses;i++) {
            if (indgrees[i]==0) {
                qu.push(i);
            }
        }

        vector<int> res;

        while (!qu.empty()) {
            int index = qu.front();
            qu.pop();
            res.push_back(index);
            for (auto i:ajac[index]) {
                indgrees[i]--;
                if (indgrees[i]==0) {
                    qu.push(i);
                }
            }
        }

        if (res.size() != numCourses) {
            return vector<int>();
        }

        return res;
    }
};


int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1,0},{2,0},{3,1},{3,2}};

    Solution s;
    vector<int> res = s.findOrder(numCourses, prerequisites);

    for (auto i:res) {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
