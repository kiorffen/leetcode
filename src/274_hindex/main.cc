/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/26
* @brief  
*
**/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int len = citations.size();
        int h=0;
        for (int i=0;i<len;i++) {
            if (citations[i]>=i+1) {
                h=i+1;
            } else {
                break;
            }
        }
        return h;
    }
};

int main() {
    vector<int> citations = {3,7,6,9,5};

    Solution s;

    int ret = s.hIndex(citations);

    cout << ret << endl;
    
    return 0;
}
