/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2022/03/05
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
#include <set>

using namespace std;

void find(vector<int> &input, vector<int> &once, set<int> &used, vector<vector<int>> &res) {
    if (once.size() == input.size()) {
        res.push_back(once);
    }
    for (int i=0; i<input.size(); i++) {
        if (used.find(input[i]) == used.end()) {
            used.insert(input[i]);
            once.push_back(input[i]);
            find(input, once, used, res);
            once.pop_back();
            used.erase(input[i]);
        }
    }
}


vector<vector<int>> all_sort(int n) {
    vector<int> input;
    for (int i=0; i<n; i++) {
        input.push_back(i+1);
    }

    vector<vector<int>> res;
    vector<int> once;
    set<int> used;
    string s1;
    map<int,int> m1;
    find(input, once, used, res);


    return res;
}

int main() {

    auto res = all_sort(5);

    for (auto v:res) {
        for (auto i:v) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
