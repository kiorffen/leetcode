/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/04/27
* @brief  
*
**/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int m = array.size();
        if (m==0) {
            return false;
        }
        int n = array[0].size();
        if (n==0) {
            return false;
        }
        
        int i=m-1;
        int j=0;
        while (i>=0&&j<n) {
            if (array[i][j]<target) {
                j++;
            } else if (array[i][j]>target) {
                i--;
            } else {
                return true;
            }
        }
        
        return false;
    }
};
