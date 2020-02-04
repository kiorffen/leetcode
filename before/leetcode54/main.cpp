/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/21
* @brief  
*
**/

#include <cstdio>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0) {
            return res;
        }
        int leftoffset = 0;
        int rightoffset = 0;
        int topoffset = 0;
        int bottomoffset = 0;
        int n = matrix[0].size();
        int m = matrix.size();
        printf("%d %d\n", m, n);
        while (true) {
            for (int i = leftoffset; i < n - rightoffset; i++) {
                res.push_back(matrix[topoffset][i]);
            }
            topoffset++;
            if (topoffset+bottomoffset == m) {
                break;
            }

            for (int i = topoffset; i < m - bottomoffset; i++) {
                res.push_back(matrix[i][n-rightoffset - 1]);
            }
            rightoffset++;
            if (leftoffset+rightoffset == n) {
                break;
            }

            for (int i = n - rightoffset - 1; i >= leftoffset; i--) {
                res.push_back(matrix[m-bottomoffset - 1][i]);
            }
            bottomoffset++;
            if (bottomoffset+topoffset == m) {
                break;
            }

            for (int i = m - bottomoffset - 1; i>= topoffset; i--) {
                res.push_back(matrix[i][leftoffset]);
            }
            leftoffset++;
            if (leftoffset+rightoffset == n) {
                break;
            }
        }

        return res;
    }
};

int main() {

    vector<vector<int>> matrix;
    int count = 0;
    for (int i = 0; i < 3; i++) {
        vector<int> tmp;
        for (int j = 0; j < 5; j++) {
            tmp.push_back(count);
            count++;
        }
        matrix.push_back(tmp);
    }

    Solution s;
    vector<int> res;
    res = s.spiralOrder(matrix);

    for (int i = 0; i < res.size(); i++) {
        printf("%d ", res[i]);
    }
    printf("\n");

    return 0;
}
