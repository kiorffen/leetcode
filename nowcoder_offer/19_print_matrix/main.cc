/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/06
* @brief  
*
**/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if (matrix.size()==0){
            return res;
        }
        if (matrix[0].size()==0) {
            return res;
        }
        int up =0;
        int left=0;
        int right = matrix[0].size()-1;
        int down = matrix.size()-1;
        
        int col,row;
        while (1) {
            row=up;
            for (col=left;col<=right;col++) {
                res.push_back(matrix[row][col]);
            }
            up++;
            if (up>down) {
                break;
            }
            
            col=right;
            for (row=up;row<=down;row++) {
                res.push_back(matrix[row][col]);
            }
            right--;
            if (right<left) {
                break;
            }
            
            row=down;
            for (col=right;col>=left;col--) {
                res.push_back(matrix[row][col]);
            }
            down--;
            if (up>down) {
                break;
            }
            
            col=left;
            for (row=down;row>=up;row--) {
                res.push_back(matrix[row][col]);
            }
            left++;
            if (right<left) {
                break;
            }
        }
        
        return res;
    }
};
