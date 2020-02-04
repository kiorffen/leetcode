/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   palindrome_number.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/07
* @brief  
*
**/

#include <cstdio>

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0 || (x != 0 && x%10 == 0)) {
                return false;
            }
            int num = 0;
            while (num < x) {
                num = num * 10 + x % 10;
                x = x / 10;
            }
            return (x == num || num/10 == x);
        }
};

int main() {

    Solution s;
    printf("%d\n", s.isPalindrome(-1));
    printf("%d\n", s.isPalindrome(10));
    printf("%d\n", s.isPalindrome(11));
    printf("%d\n", s.isPalindrome(121));

    return 0;
}
