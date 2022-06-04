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
#include <string>

using namespace std;

int find_scope(vector<int> &a, int target) {
    int left=0, right=0, sum=0, min=a.size();

    while(right < a.size()) {
        right++;
        sum+=a[right];
        cout<<"right: " << right << endl;
        while(sum>=target) {
            int temp = right-left+1;
            if (min>temp) {
                min = temp;
            }
            sum-=a[left];
            left++;
            cout<<"left: " << left << endl;
        }
    }

    return min;
}

int main() {
    vector<int> a = {1,9,1,1,9,4,5,6,2,2,19};
    auto res = find_scope(a, 12);

    cout<<res<<endl;

    return 0;
}
