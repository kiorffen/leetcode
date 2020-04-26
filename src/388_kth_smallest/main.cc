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
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size()-1;
        int left=matrix[0][0];
        int right = matrix[n][n];

        while (left<right) {
            int mid=left+(right-left)/2;
            int cnt = countLessMid(matrix, mid, n);
            if (cnt<k) {
                left = mid+1;
            } else {
                right=mid;
            }
        }

        return left;
    }

    int countLessMid(vector<vector<int>>& matrix, int mid, int n) {
        int cnt = 0;
        int x=0;
        int y=n;
        while (x<=n&&y>=0) {
            if (matrix[y][x]<=mid) {
                cnt+=y+1;
                x++;
            } else {
                y--;
            }
        }

        return cnt;
    }
};

int main() {
    Solution s;
    vector<vector<int>> matrix={{1,5,9},{10,11,13},{12,13,15}};

    int ret = s.kthSmallest(matrix, 8);

    cout << ret << endl;

    return 0;
}
