/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/02/09
* @brief  
*
**/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

bool comp(const string a, const string b) {
    return a+b>b+a;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res;
        vector<string> strs;

        bool unzero = false;
        for (auto i:nums) {
            if (i!=0) {
                unzero = true;
            }
            string tmp;
            stringstream ss;
            ss<<i;
            ss>>tmp;
            strs.push_back(tmp);
        }
        if (!unzero) {
            return "0";
        }

        sort(strs.begin(),strs.end(),comp);

        for (auto s:strs) {
            res+=s;
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    nums.push_back(121);
    nums.push_back(12);

    string res = s.largestNumber(nums);
    cout << res<<endl;

    return 0;
}

//class Solution {
//public:
//    string largestNumber(vector<int>& nums) 
//    {
//        if (all_of(nums.begin(), nums.end(), [](int x) { return x == 0; })) {
//            return string("0");
//        }
//        vector<string> strNums(nums.size());
//        std::transform(nums.begin(), nums.end(), strNums.begin(), [](int x) {
//            return std::to_string(x);
//        });
//
//        std::sort(strNums.begin(), strNums.end(), [](const string& x, const string& y) {
//            /* x为后面元素，y为前面元素，return true则将x移动到前面 */
//            return x + y > y + x;
//        });
//
//        return std::accumulate(strNums.begin(), strNums.end(), string());
//    }
//};
