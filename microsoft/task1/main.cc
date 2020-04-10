/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/06
* @brief  
*
**/
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int>& A) {
    int ans = 0;
    for (int i = 1; i < A.size(); i++) {
        if (ans > A[i]) {
            ans = A[i];
        }
    }
    return ans;
}

int main() {
    vector<int> nums;
    nums.push_back(-111000);
    nums.push_back(-1);
    nums.push_back(-332);
    nums.push_back(-2);

    int ret = solution(nums);

    cout << ret << endl;
}

