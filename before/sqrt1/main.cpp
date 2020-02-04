/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/17
* @brief  
*
**/

#include <cstdio>
#include <cstdlib>
#include <cmath>

float my_sqrt(float n) //用二分法 
{ 
    float eps = 0.00001;
    if (n < 0) {
        return n;
    }

    float up = 0.0;
    float down = 0.0;
    float mid = 0.0;
    if (n*n >= n) {
        up = n;
        mid = (down + up) / 2;
        while (mid*mid - n > eps || mid*mid - n < -eps) {
            if (mid*mid > n) {
                up = mid;
                mid = (down + up) / 2;
            } else {
                down = mid;
                mid = (down + up) / 2;
            }
        }
    } else {
        down = n;
        up = 1;
        while (mid*mid - n > eps || mid*mid - n < -eps) {
            if (mid*mid > n) {
                up = mid;
                mid = (down + up) / 2;
            } else {
                down = mid;
                mid = (down + up) / 2;
            }
        }
    }

    return mid;
}

int main() {
    printf("%f\n", my_sqrt(16));
    printf("%f\n", my_sqrt(2));
    printf("%f\n", my_sqrt(0.09));

    return 0;
}
