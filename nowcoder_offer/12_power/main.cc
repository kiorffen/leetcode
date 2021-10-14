/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/06
* @brief  
*
**/

#include <iostream>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if (base==0) {
            return 0;
        }
        
        if (exponent==0) {
            return 1;
        }
        
        if (exponent%2==0) {
            return Power(base,exponent/2) * Power(base,exponent/2);
        } else {
            return base * Power(base,exponent-1);
        }
    }
};

class Solution {
public:
    double Power(double base, int exponent) {
        if (base==0) {
            return 0;
        }
        
        int flag=0;
        if (exponent<0) {
            flag=1;
            exponent = -exponent;
        }
        
        double ret = spower(base, exponent);
        
        if (flag==0) {
            return ret;
        } else {
            return 1/ret;
        }
        
        
        
        
    }
    double spower(double base, int exponent) {
        if (exponent==0) {
            return 1;
        }
        if (exponent==1) {
            return base;
        }
        
        double sub = Power(base,exponent/2);
        if (exponent%2==0) {
            return sub * sub;
        } else {
            return base * sub * sub;
        }
    }
};

int main() {
    Solution s;

    double ret = s.Power(2,6);

    cout << ret << endl;

    return 0;
}
