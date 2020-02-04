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
using std::cout;
using std::endl;

class Solution {
public:
    int mySqrt(int x) {
        if (x<2) return x;
        int l = 1;
        int r = x;
        int ret = 0;
        while (l<r) {
            int m = l+(r-l)/2;    
            if (m>x/m) {
                r=m;
            } else {
                l=m+1;
            }
        }

        if (r>x/m)return r-1;
        return r;
    }

};

int main() {
    Solution s;

    cout<< s.mySqrt(1) << endl;
    cout<< s.mySqrt(8) << endl;
    cout<< s.mySqrt(7) << endl;
    cout<< s.mySqrt(17) << endl;
    cout<< s.mySqrt(27) << endl;
    cout<< s.mySqrt(25) << endl;
}
