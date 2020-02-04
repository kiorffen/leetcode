/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/29
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        for (int i =0; i <n;i++) {
            int head = 1 << i;
            cout << "head: "<< head << endl;
            for (int j=ret.size()-1;j>=0;j--) {
                cout << ret[j] << " ";
                ret.push_back(head+ret[j]);
            }
            cout << endl;
        }

        return ret;
    }
};

int main() {

    Solution s;

    vector<int> ret = s.grayCode(0);
    for (auto i:ret) {
        cout << i << ",";
    }
    cout << endl;
    ret = s.grayCode(1);
    for (auto i:ret) {
        cout << i << ",";
    }
    cout << endl;
    ret = s.grayCode(2);
    for (auto i:ret) {
        cout << i << ",";
    }
    cout << endl;
    ret = s.grayCode(3);
    for (auto i:ret) {
        cout << i << ",";
    }
    cout << endl;
    ret = s.grayCode(4);
    for (auto i:ret) {
        cout << i << ",";
    }
    cout << endl;


    return 0;
}
