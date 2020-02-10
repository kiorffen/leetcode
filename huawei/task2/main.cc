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
#include <vector>
#include <map>

using namespace std;

struct Info {
    int s;
    int e;
};

bool check(Info info,int index, vector<Info>&maxs) {
    int l = index, r = index+1;
    int ls = 0, rs = 0;
    int len = 0;
    while (1) {
        if (l>=0) {
            Info t1 = maxs[l];
            if (t1.s<=info.s&&t1.e>=info.e) {
                l=l-1;
                len++;
            } else {
                ls = 1;
            }
        }
    cout << "l:" <<l<<"r:" << r <<"len:"<< len << endl;
        if (len == info.e-info.s+1) {
            return true;
        }
        if (r<maxs.size()) {
            Info t1 = maxs[r];
            if (t1.s<=info.s&&t1.e>=info.e) {
                r=r+1;
                len++;
            } else {
                rs=1;
            }
        }
    cout << "l:" <<l<<"r:" << r <<"len:"<< len << endl;
        if (len == info.e-info.s+1) {
            return true;
        }
        if (rs==1&& ls==1) {
            break;
        }
        if (l<0 && r>maxs.size()) {
            break;
        }
    }

    return false;
}

int main() {
    int N;
    vector<string> inputs;

    cin >> N;

    string tmp;
    for (int i=0;i<N;i++) {
        tmp.clear();
        cin>>tmp;
        inputs.push_back(tmp);
    }

    if (N==1) {
        for (auto c:inputs[0]) {
            if (c=='1') {
                cout << 1 << endl;
                return 0;
            }
        }
        cout << 0 << endl;
        return 0;
    }

    vector<Info> maxs;
    int ms=0,me=0,ml=0;
    int s=-1,e=0,l=0;
    for (int i =0;i<inputs.size();i++) {
        for (int j=0;j<inputs[i].size();j++) {
            if (inputs[i][j]=='1') {
                if (s<0) {
                    s=j;
                }
                l=l+1;
            } else {
                if (l>0) {
                   e = s+l-1;
                   if (l>ml) {
                       ml = l;
                       ms = s;
                       me = e;
                   }
                   l=0;
                   s=-1;
                }
            }
        }
        if (l>0) {
           e = s+l-1;
           if (l>ml) {
               ml = l;
               ms = s;
               me = e;
           }
           l=0;
        }
        Info info;
        info.s = ms;
        info.e = me;
        maxs.push_back(info);
    }

    vector<int> ret;
    for (int i=0;i<maxs.size();i++) {
        Info info = maxs[i];
        if (check(info, i, maxs)) {
            int num = (info.e-info.s+1)*(info.e-info.s+1);
            ret.push_back(num);
        }
    }

    int max =0;
    for (auto i:ret) {
        if (max<i) {
            max=i;
        }
    }

    cout << max << endl;

    return 0;
}
