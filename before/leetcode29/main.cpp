/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/18
* @brief  
*
**/

#include <cstdio>
#include <cstdlib>
#include <math.h>

#define MAX_INT ((1 << 31) - 1)

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == MAX_INT || divisor == 0) {
            return MAX_INT;
        }
        int ret = 0;
        bool is_negative = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            is_negative = true;
        }
        long long i_dividend = labs(dividend);
        long long i_divisor = labs(divisor);

        while (i_dividend >= i_divisor) {
            i_dividend -= i_divisor;
            ret += 1;
        }

        return is_negative ? -ret : ret;
    }
};

int main() {
    Solution s;

    printf("%d\n", s.divide(-2147483648,-1));
}
