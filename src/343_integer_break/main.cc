/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/10
* @brief  
*
**/

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if (n<=3) {
            return n-1;
        }
        int a=n/3;
        int b=n%3;
        if (b==0) {
            return pow(3,a);
        } else if (b==1) {
            return pow(3,a-1)*4;
        }
        return pow(3,a)*2;
    }

};

int main() {

    Solution s;

    int ret = s.integerBreak(10);
    cout << ret << endl;

    return 0;
}
