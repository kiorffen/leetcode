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
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> output;
        vector<int> vec;
        output.push_back(vec);

        for (int i = 1; i<=nums.size(); i++) {
            backstrace(nums,i,0,output,vec);
        }

        return output;
    }
    void backstrace(vector<int> &nums, int k, int start, vector<vector<int>> &output, vector<int>& vec) {
        cout << "k: " << k << " start: " << start<< endl;
        if (vec.size() == k) {
            output.push_back(vec);
        }

        for (int j=start;j<nums.size();j++) {
            cout << "j: "<<j<<endl;
            vec.push_back(nums[j]);
            backstrace(nums,k,j+1,output,vec);
            vec.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1,2,3};
    vector<vector<int>> output = s.subsets(v);
    for (auto v:output) {
        for (auto i:v) {
            cout <<i<<" ";
        }
        cout << endl;
    }


    return 0;
}
