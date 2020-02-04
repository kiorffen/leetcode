/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/21
* @brief  
*
**/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int  main() {
    int n;
    cin >> n;
    set<int> s;
    vector<int> vec;
    for (int i = 0;i<n;i++) {
        int a;
        cin>>a;
        if (s.find(a) != s.end()) {
            continue;
        }
        s.insert(a);
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    
    for(auto i:vec) {
        cout<<i << endl;
    }
}
