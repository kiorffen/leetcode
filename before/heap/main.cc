/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/15
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    vector<int> a = {6,5,2,4,3,1,7,9,8};

    for (auto i:a) {
        cout << i <<" ";
    }
    cout << endl;

    make_heap(a.begin(), a.end());

    for (auto i:a) {
        cout << i <<" ";
    }
    cout << endl;

    push_heap();

    return 0;
}
