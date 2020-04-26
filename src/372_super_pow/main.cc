/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/26
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {

private:
    int base = 1337;

public:

    int mypow(int a, int k) {
        if (k==0) {
            return 1;
        }
        a%=base;

        if (k%2==1) {
            return (a*mypow(a,k-1)) % base;
        } else {
            int sub = mypow(a,k/2);
            return (sub*sub)%base;
        }
    }

    int superPow(int a, vector<int>& b) {

        if (b.empty()) {
            return 1;
        }

        int last = b.back();
        b.pop_back();
        int part1 = mypow(a,last);
        int part2 = mypow(superPow(a,b), 10);

        return (part1*part2)%base;

    }
};

int main() {
    Solution s;
    int a =2;
    vector<int> b = {1,0};

    int ret = s.superPow(a,b);
    cout << ret << endl;

    return 0;
}
