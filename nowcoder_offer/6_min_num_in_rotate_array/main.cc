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

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if (len==0) {
            return 0;
        }
        int left = 0;
        int right = len-1;
        while (left<right) {
            int mid = left+(right-left)/2;
            cout << "mid: " << mid << " left: " << left << " right: " << right << endl;
            int data = rotateArray[mid];
            if (data>rotateArray[right]) {
                left = mid+1;
            } else if (data<rotateArray[right]) {
                right = mid;
            } else {
                left++;
            }
        }
        
        return rotateArray[left];
    }
};

//class Solution {
//public:
//    int minNumberInRotateArray(vector<int> rotateArray) {
//        int len = rotateArray.size();
//        if (len==0) {
//            return 0;
//        }
//        int left = 0;
//        int right = len-1;
//        while (left<right) {
//            int mid = left+(right-left)/2;
//            int data = rotateArray[mid];
//            if (data>rotateArray[right]) {
//                left = mid+1;
//            } else if (data<rotateArray[right]) {
//                right = mid;
//            }
//        }
//        
//        return rotateArray[left];
//    }
//};

int main() {
    Solution s;

    vector<int> nums = {1,1,1,1};
    int ret = s.minNumberInRotateArray(nums);

    cout << ret << endl;

    return 0;
}
