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
*/

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) return false;
        int n = matrix[0].size();
        int l=0,r=m*n-1;

        while(l<=r) {
            int p = (l+r)/2;
            int d = matrix[p/n][p%n];
            //cout << "p: " << p <<endl;
            //cout << "d: " << d <<endl;
            //cout << "l: " << l <<endl;
            //cout << "r: " << r <<endl;
            if (d == target) {
                return true;
            } else if (d < target) {
                l=p+1;
            } else {
                r=p-1;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> a = {{1,3,5,7},{10, 11, 16, 20},{23, 30, 34, 50}};
    for (auto v : a) {
        for (auto i :v) {
            cout<<i<< " ";
        }
        cout<<endl;
    }
    int da = 10;
    shared_ptr<int> pa = make_shared<int>(da);
    Solution s;
    cout<<s.searchMatrix(a,3)<<endl;
    cout<<s.searchMatrix(a,20)<<endl;
    cout<<s.searchMatrix(a,29)<<endl;
}
