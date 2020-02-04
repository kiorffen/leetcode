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
        int l = 0;
        int r = x;
        int m = x;
        int gap = x*x;
        int ret = 0;
        while (1) {
            if (m*m>x) {
                if (m*m-x > gap) break;
                gap = m*m -x;
                r=m;
            } else {
                if (x-m*m > gap) break;
                gap = x - m*m;
                l=m;
            }
            cout <<"l: "<< l << endl;
            cout <<"r: "<< r << endl;
            cout <<"m: "<< m << endl;
            cout <<"gap: "<< gap << endl;
            ret = m;
            m = (l+r)/2;
        }

        return ret;
    }

};

int main() {
    Solution s;

    cout<< s.mySqrt(1) << endl;
    cout<< s.mySqrt(8) << endl;
    cout<< s.mySqrt(7) << endl;
}
