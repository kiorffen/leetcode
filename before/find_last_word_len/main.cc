/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/12/21
* @brief  
*
**/


#include <iostream>
#include <string>

using namespace std;

int findLastWordLen(string s) {
    
    int i = s.size()-1;
    int cnt = 0;
    while(1) {
        if (i<0) {
            break;
        }
        if (s[i] == ' ') {
            break;
        }
        i--;
        cnt++;
    }
    
    return cnt;
}

int main() {
    string a;
    getline(cin, a);
    cout << findLastWordLen(a) << endl;
}
