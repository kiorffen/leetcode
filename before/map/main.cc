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
#include <map>

using namespace std;

int main() {

    map<int,int> a;

    a[1]=1;
    a[2]=1;

    for (auto i:a) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}
