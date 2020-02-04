/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/22
* @brief  
*
**/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> output;

        vector<int> vec;
        backstrace(1,n,k,output,vec);

        return output;
    }

    void backstrace(int i, int n, int k, vector<vector<int>> &output, vector<int>& vec) {
        //cout << "i: " << i << endl;
        if (vec.size() == k) {
            output.push_back(vec);
        }

        for (int j=i;j<=n;j++) {
            vec.push_back(j);
            backstrace(j+1,n,k,output,vec);
            vec.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> output = s.combine(4,2);
    for (auto v:output) {
        for (auto i:v) {
            cout <<i<<" ";
        }
        cout << endl;
    }


    return 0;
}
