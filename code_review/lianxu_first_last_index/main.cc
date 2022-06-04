/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2022/03/08
* @brief  
*
**/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int find_first_last_index(vector<int> &a, int target, int flag) {
    vector<int> res;
    int left=0;
    int right=a.size()-1;
    
    while(left<right) {
        int mid = (left+right)/2;
        if(a[mid]>target || (flag && a[mid]>=target)) {
            right = mid;
        } else {
            left = mid+1;
        }
        cout << "step: "<< left << " " << right << endl;
    } 

    return right;
}

int main() {
    vector<int> a = {1,2,2,3,4,5,6};
    int first = find_first_last_index(a, 2, true);
    int last = find_first_last_index(a, 2, false) - 1;

    cout << first << " " << last << endl;
}
