/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/27
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
private:
    vector<int> steps = {1,2};
public:
    int jumpFloor(int number) {
        int kinds = 0;
        map<int,int> memory;
        kinds=dfs(number, memory);
        return kinds;
    }
    
    int dfs(int number,  map<int,int>& memory) {
        if (number==0) {
            return 1;
        }
        
        if (memory.find(number)!=memory.end()) {
            return memory[number];
        }
        
        int kinds = 0;
        for (auto s:steps) {
            if (number-s>=0) {
                kinds+=dfs(number-s,memory);
            }
        }
        memory[number] = kinds;
        return kinds;
    }

    int jumpFloor1(int number) {
        vector<int> dp(number+1,0);
        dp[0]=1;

        for (int i=1;i<=number;i++) {
            for (auto s:steps) {
                if (i>=s) {
                    dp[i]+=dp[i-s];
                }
            }
        }

        return dp[number];
    }
};

int main() {
    Solution s;

    int ret = s.jumpFloor1(4);

    cout << ret << endl;
}
