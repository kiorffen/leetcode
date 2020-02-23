/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/23
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) {
            return false;
        }
        int n = matrix[0].size();
        if (n==0) {
            return false;
        }

        int left=0,right=n-1;
        int up=0,bottom=m-1;

        while (left<right||up<bottom) {
            int rmid = (up+bottom)/2;
            int cmid = (left+right)/2;

            cout << "up:" << up << " rmid: " << rmid << " bottom: " << bottom<< endl;
            cout << "left: "<<left << " cmid: " << cmid << " right: "<< right << endl;
            cout << "num: " << matrix[rmid][cmid] << endl;

            if (matrix[rmid][cmid]==target) {
                return true;
            }

            if (rmid-1>=up && matrix[rmid-1][cmid]>=target) {
                bottom = rmid;
            }
            if (rmid+1<=bottom && matrix[rmid+1][cmid]<=target) {
                up = rmid+1;
            }
            if (cmid-1>=left && matrix[rmid][cmid-1]>=target) {
                right = cmid;
            }
            if (cmid+1<=right && matrix[rmid][cmid+1]<=target) {
                left = cmid+1;
            }
        }

        return false;
    }
    bool searchMatrix1(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m==0) {
            return false;
        }
        int n = matrix[0].size();
        if (n==0) {
            return false;
        }

        int i = m-1;
        int j = 0;

        while (i>=0 && j<=n-1) {
            if (matrix[i][j] < target) {
                j++;
            } else if (matrix[i][j]>target) {
                i--;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<int>> matrix = {{1,   4,  7, 11, 15},{2,   5,  8, 12, 19},{3,   6,  9, 16, 22},{10, 13, 14, 17, 24},{18, 21, 23, 26, 30}};

    Solution s;
    cout << s.searchMatrix1(matrix, 5) << endl;

    return 0;
}
