/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   test.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/17
* @brief  
*
**/
#include <cstdlib>
#include <cstdio>

// 只能处理比1大的数

double my_sqrt(double n) //用二分法 
{ 
    double eps = 0.00001;
    if(n<0) //小于0的按照你需要的处理 
        return n; 
    double ans; 
    double low,up; 
    low=0,up=n; 
    ans=(low+up)/2; 
    while(ans*ans-n>eps || ans*ans-n<-eps) 
    { 
        if(ans*ans>n) 
            up=ans; 
        else 
            low=ans; 
        ans=(up+low)/2; 
    } 
    return ans; 
}

int main() {

    printf("%f\n", my_sqrt(9));

    return 0;
}

