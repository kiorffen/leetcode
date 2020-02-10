/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/09
* @brief  
*
**/

#include <iostream>
#include <climits>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int zeros = 0;
        while (n>m) {
            zeros++;
            n=n>>1;
            m=m>>1;
        }
        return m<<zeros;
    }
    int rangeBitwiseAnd1(int m, int n) {
        while (n>m) {
            n=n&(n-1);
        }
        return n;
    }
};

int main() {
    Solution s;
    int ret = s.rangeBitwiseAnd1(5,7);
    cout << ret << endl;

    return 0;
}
