/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/05
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int k = 1;
        for (int i = len-1;i>=0;i--) {
            if (citations[i]<k) {
                break;
            }
            k++;
        }

        return k-1;
    }
    int hIndex1(vector<int>& citations) {
        int len = citations.size();
        int left = 0;
        int right = len - 1;
        int pivot = 0;
        while (left <= right) {
            pivot = left + (right-left)/2;
            if (citations[pivot] == len - pivot) {
                cout << "step1" << endl;
                return len - pivot;
            } else if (citations[pivot] < len-pivot) {
                cout << "step2" << endl;
                left = pivot + 1;
            } else {
                right = pivot - 1;
                cout << "step3" << endl;
            }
        }

        return len - left;
    }
};

int main() {
    Solution s;
    vector<int> citations = {0};

    int ret = s.hIndex1(citations);
    cout << ret << endl;

    return 0;
}
