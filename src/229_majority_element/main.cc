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

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        if (len==0) {
            return res;
        }

        vector<int> cands(2, nums[0]);
        vector<int> cnts(2, 0);

        int num;
        for (int i=0;i<len;i++) {
            num = nums[i];
            bool flag=false;
            for (int j=0;j<cands.size();j++) {
                if (num==cands[j]) {
                    ++cnts[j];
                    flag=true;
                    break;
                }
            }

            if (!flag) {
                bool flag2 = false;
                for (int j=0;j<cands.size();j++) {
                    if (cnts[j]==0) {
                        cands[j]=num;
                        ++cnts[j];
                        flag2=true;
                    }
                }

                if (!flag2) {
                    for (int j=0;j<cands.size();j++) {
                        --cnts[j];
                    }
                }
            }
        }

        for (auto i:cands) {
            cout << "cands: " << i << endl;
        }

        if (cands[0]==cands[1]) {
            cands.pop_back();
        }

        cnts[0]=0;
        cnts[1]=0;

        for (int i=0;i<len;i++) {
            num=nums[i];
            for (int j=0;j<cands.size();j++) {
                if (num==cands[j]) {
                    cnts[j]++;
                    break;
                }
            }
        }

        for (int j=0;j<cands.size();j++) {
            if (cnts[j]>len/3) {
                res.push_back(cands[j]);
            }
        }

        return res;

    }

    vector<int> majorityElement1(vector<int>& nums) {
        int len = nums.size();
        vector<int>res, cands, cnts;
        if(len == 0){//没有元素，直接返回空数组
            return res;
        }
        cands.assign(2, nums[0]);
        cnts.assign(2, 0);
        //第1阶段 成对抵销
        for(auto num: nums){
            bool flag = false;
            for(int i = 0; i < cands.size(); ++i){
                if(num == cands[i]){
                    ++cnts[i];
                    flag = true;
                    break;
                }
            }
            if(!flag){
                bool flag2 = false;
                for(int j = 0; j < cands.size(); ++j){
                    if(cnts[j] == 0){
                        flag2 = true;
                        cands[j] = num;
                        cnts[j]++;
                    }
                }
                if(!flag2){
                    for(int j = 0; j < cnts.size(); ++j){
                        --cnts[j];
                    }
                }
            }
        }

        //第2阶段 计数 数目要超过三分之一
        cnts[0] = cnts[1] = 0;
        if(cands[0] == cands[1])
            cands.pop_back();
        for(auto num:nums){
            for(int i = 0; i < cands.size(); ++i){
                if(cands[i] == num){
                    ++cnts[i];
                    break;
                }
            }
        }
        for(int i = 0; i < cands.size(); ++i){
            if(cnts[i] > len / 3){
                res.push_back(cands[i]);
            }
        }
        return res;
    }
};

int  main() {
    Solution s;
    vector<int> nums={1,1,1,3,3,2,2,2};
    vector<int> res = s.majorityElement(nums);

    for (auto i:res) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
