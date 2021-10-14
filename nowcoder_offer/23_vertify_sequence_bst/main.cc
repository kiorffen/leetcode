/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/05/07
* @brief  
*
**/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.size()==0) {
            return false;
        }
        
        int left=0;
        int right = sequence.size()-1;
        
        return vertify(sequence, left, right);
    }
    
    bool vertify(vector<int> sequence, int left, int right) {
        cout << "left: "<< left << " right: " << right << endl;
        if (left>=right) {
            return true;
        }
        
        int root=sequence[right];
        int split=left;
        for (;split<right;split++) {
            if (sequence[split] > root) {
                break;
            }
        }
        cout << "split: " << split << endl;
        for (int i=split;i<right;i++) {
            if (sequence[i]<root) {
                return false;
            }
        } 
        
        return vertify(sequence,left,split-1)&&vertify(sequence,split,right-1);
        
    }
};

int main() {
    vector<int> nums = {4,6,7,5};

    Solution s;
    bool ret = s.VerifySquenceOfBST(nums);
    cout << ret << endl;

    return 0;
}
