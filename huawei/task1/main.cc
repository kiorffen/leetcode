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

int main() {
    int a,b,c,num;
    string type,mode;

    cin >> a >> b >> c >> num >>type >> mode;
    if (a<=0 || b<=0 || c<=0 || num <=0) {
        cout << "ERROR" << endl;
        return 0;
    }
    if (type!="HKD"&&type!="CNY"&&type!="USD"&&type!="GBP") {
        cout << "ERROR" << endl;
        return 0;
    }

    if (mode!="MIN"&&mode!="MAX") {
        cout << "ERROR" << endl;
        return 0;
    }

    int gh,uh,ch;
    ch = a;
    uh = a*b;
    gh = a*b*c;

    int totalh = 0;
    if (type=="HKD") {
        totalh = num;
    } else if (type=="CNY") {
        totalh = num * a;
    } else if (type=="USD") {
        totalh = num * a * b;
    } else if (type=="GBP") {
        totalh = num * a * b *c;
    }

    if (mode=="MIN") {
        cout << totalh << " " << "HKD" << endl;
        return 0;
    }
    int gn,un,cn,hn;
    if (mode=="MAX") {
        gn = totalh/gh;
        totalh = totalh % gh;

        un = totalh / uh;
        totalh = totalh % uh;

        cn = totalh / ch;
        hn = totalh % ch;
    }

    bool pre = false;
    if (gn>0) {
        cout << gn << " GBP"; 
        pre = true;
    }
    if (un>0) {
        if (pre) {
            cout << " ";
        }
        cout << un << " USD";
        pre = true;
    }
    if (cn>0) {
        if (pre) {
            cout << " ";
        }
        cout << cn << " CNY";
        pre = true;
    }
    if (hn > 0) {
        if (pre) {
            cout << " ";
        }
        cout << hn << " HKD";
    }
    cout << endl;

    return 0;
}
