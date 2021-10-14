/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/07
* @brief  
*
**/

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int>& pushV,vector<int>& popV) {
        stack<int> stk;
        if (pushV.size()==0 || popV.size()==0 || pushV.size()!=popV.size()) {
            return false;
        }
        
        int j=0;
        for (int i=0;i<pushV.size();i++) {
            stk.push(pushV[i]);
            while (!stk.empty() && stk.top()==popV[j]) {
                j++;
                stk.pop();
            }
        }
        return stk.empty();
    }
};

int main() {

    Solution s;
    vector<int> push={1,2,3,4,5};
    vector<int> pop = {4,3,5,1,2};

    bool ret = s.IsPopOrder(push, pop);

    cout << ret << endl;


    return 0;
}
