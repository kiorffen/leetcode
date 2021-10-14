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

class Solution {
public:
     int  NumberOf1(int n) {
         int cnt = 0;
         while (n) {
             n = n&(n-1);
             cnt++;
         }
         return cnt;
     }
    
};
