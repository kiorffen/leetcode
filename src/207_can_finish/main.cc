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
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //入度数组
        vector<int> indegrees(numCourses, 0);
        //邻接矩阵数组
        vector<vector<int>> ajac(numCourses, vector<int>());

        //初始化所有节点的临界矩阵和入度,[0,1]表示1->0
        for (auto v:prerequisites) {
            ajac[v[1]].push_back(v[0]);
            indegrees[v[0]]++ ;
        }

        queue<int> qu;

        int cnt = 0;
        //所有入度为0的节点先入队列
        for (int i=0;i<indegrees.size();i++) {
            if (indegrees[i]==0) {
                qu.push(i);
                cnt++;
            }
        }

        while (!qu.empty()) {
            int tmp = qu.front();
            qu.pop();
            // 所有邻接矩阵的入度减一，有0的入度节点继续加入队列
            for (auto i:ajac[tmp]) {
                indegrees[i]--;
                if (indegrees[i]==0) {
                    qu.push(i);
                    cnt++;
                }
                //满足课程数量
                if (cnt==numCourses) {
                    return true;
                }
            }
        }

        // 只有一门课的边界条件
        return cnt==numCourses;
    }
};

int main() {
    int numCourses = 3;
    vector<vector<int>> prerequisites = {{0,1},{1,2},{0,2}};

    Solution s;
    bool ret = s.canFinish(numCourses,prerequisites);

    cout << ret << endl;
    cout << true << endl;


    return 0;
}
