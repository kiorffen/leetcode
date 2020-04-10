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

#include <iostream>
#include <vector>

using namespace std;

void btrace(vector<int> &A, int M, vector<int>& subsets, vector<int> &nums, int one, int start) {

    if (start==A.size()) {
        nums.push_back(one);
        return;
    }

    for (int i = start;i<A.size();i++) {
        bool flag = true;
        for (auto j:subsets) {
            if (A[i]%M!=0) {
                flag=false;
                break;
            }
        }
        if (flag) {
            subsets.push_back(A[i]);
            one++;
            btrace(A,M,subsets,nums, one,i+1);
            subsets.pop_back();
            one--;
        }
    }
}

int solution(vector<int> &A, int M) {
    // write your code in C++14 (g++ 6.2.0)
    // 
    vector<int> nums;
    vector<int> subsets;
    int one = 0;
    int start = 0;

    btrace(A,M,nums,subsets,one, start);

    int max = 0;
    for (auto i:nums) {
        if (max<i) {
            max=i;
        }
    }

    return max;
}


int main() {
    vector<int> nums;
    nums.push_back(-3);
    nums.push_back(-2);
    nums.push_back(1);
    nums.push_back(0);
    nums.push_back(8);
    nums.push_back(7);
    nums.push_back(1);

    int M = 3;

    int ret = solution(nums, 3);

    cout << ret << endl;

}

