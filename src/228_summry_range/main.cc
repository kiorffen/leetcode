/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/22
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string itoa(int num) {
        string res;
        stringstream ss;
        ss<<num;
        ss>>res;
        return res;
    }
    int atoi(string num) {
        int res;
        stringstream ss;
        ss<<num;
        ss>>res;
        return res;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.size()==0) {
            return res;
        }
        if (nums.size()==1) {
            res.push_back(itoa(nums[0]));
            return res;
        }
        int pre=nums[0];
        int cur;
        string tmp;
        for (int i=1;i<nums.size();i++) {
            cur = nums[i];
            if (cur!=pre+1) {
                tmp = tmp+itoa(pre);
                res.push_back(tmp);
                tmp="";
            }

            if (cur==pre+1) {
                if (tmp=="") {
                    tmp=tmp+itoa(pre)+"->";
                }
            }
            pre=cur;
        }
        tmp=tmp+itoa(cur);
        res.push_back(tmp);

        return res;
    }
};

int main() {
    Solution s;

    vector<int> nums = {-1,100};

    vector<string> res = s.summaryRanges(nums);

    for (auto s:res) {
        cout << s << " ";
    }
    cout << endl;
    cout << s.atoi("-1234")<<endl;

    return 0;
}
