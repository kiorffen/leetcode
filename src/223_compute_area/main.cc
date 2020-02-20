/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/20
* @brief  
*
**/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = abs(A-C)*abs(B-D);
        int area2 = abs(E-G)*abs(F-H);

        int left = max(A,E);
        int right = min(C,G);
        int bottom = max(B,F);
        int up = min(D,H);

        if (left> right || bottom>up) {
            return area1+area2;
        }

        return area1 - abs(right-left)*abs(up-bottom) + area2;
    }
};

int main() {
    Solution s;

    int ret = s.computeArea(-3, 0, 3, 4, 0, -1, 9, 2);

    cout << ret << endl;

    return 0;
}
