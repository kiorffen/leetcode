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

using namespace std;

double gap = 1e-6;

double sqrt(int n) {
    double left=1;
    double right=n;

    while (left<right) {
        double mid = (left+right)/2;
        double m = mid*mid;
        if (m<n+gap && m>n-gap) {
            return mid;
        } else if (m>n) {
            right = mid;
        } else if (m<n) {
            left = mid;
        }
    }

    return left;
}

int main() {
    double res=sqrt(9);

    cout << res << endl;
}
