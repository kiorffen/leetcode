/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/07
* @brief  
*
**/

#include <iostream>
using namespace std;

char convert_lower_to_num(char c) {
    if (c=='a'||c=='b'||c=='c') {
        return '2';
    } else if (c=='d' || c=='e' || c=='f') {
        return '3';
    } else if (c=='g' || c=='h' || c=='i') {
        return '4';
    } else if (c=='j' || c=='k' || c=='l') {
        return '5';
    } else if (c=='m' || c=='n' || c=='o') {
        return '6';
    } else if (c=='p' || c=='q' || c=='r' || c=='s') {
        return '7';
    } else if (c=='t' || c=='u' || c=='v') {
        return '8';
    } else {
        return '9';
    }
}

char convert_upper_to_lower(char c) {
    if (c=='Z') return 'a';
    return c+33;
}

int main() {
    string s;
    string ret;

    while (cin >> s) {
        for (char c:s) {
            if (c<='z' && c>='a') {
                ret.push_back(convert_lower_to_num(c));
            } else if (c<='Z' && c>='A') {
                ret.push_back(convert_upper_to_lower(c));
            } else {
                ret.push_back(c);
            }
        }
        cout << ret << endl;
        ret.clear();
    }

    return 0;
}
