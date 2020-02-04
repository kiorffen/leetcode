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
#include <vector>

using namespace std;

int MAX_INT = 10000000;

vector<int> find_min_data(vector<vector<int>> &a, int n) {
 vector<int> ret;
 int length = a.size();
 int cnt = 0;
 while (1) {
   int j = 0;
   int min = MAX_INT;
   for (int i = 0; i< length; i++) {
     if (a[i][0] < min) {
        min = a[i][0];
        j = i;
     }
   }
   ret.push_back(min);
   cnt++;
   a[j].erase(a[j].begin());
   if (cnt == n) {
     break;
   }
 }

 return ret;
}

int main() {

    vector<vector<int>> a = {{1, 8, 10, 15, 19,  999}, {9, 10, 11, 12, 14, 888, 100000}, {8, 10, 13, 20, 33}, {4, 9, 13}};

    vector<int> b = find_min_data(a, 4);

    for (auto i:b) {
        cout << i << " ";
    }
    cout << endl;


    return 0;
}
