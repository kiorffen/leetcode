/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/05
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> exists;

    for (auto i:A) {
        exists.insert(i);
    }

    for (int i =1;i<=100000;i++) {
        auto it = exists.find(i);
        if (it==exists.end()) {
            return i;
        }
    }

    return 0;
}

int main() {
    vector<int> exists;
    exists.push_back(1);
    exists.push_back(3);
    exists.push_back(6);
    exists.push_back(4);
    exists.push_back(1);
    exists.push_back(2);

    int ret = solution(exists);

    cout << ret <<  endl;

    return 0;
}
