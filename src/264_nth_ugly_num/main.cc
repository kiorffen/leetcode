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
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int nthUglyNumber1(int n) {
        if (n==1) {
            return 1;
        }
        vector<int> step={2,3,5};
        priority_queue<long, vector<long>, greater<long>> pq;
        set<long> st;
        st.insert(1);
        vector<long> res;
        pq.push(1);
        long min_num;
        long tmp;
        int i=0;
        while (!pq.empty() && i<n) {
            min_num = pq.top();
            pq.pop();
            res.push_back(min_num);
            for (auto t:step) {
                tmp = t*min_num;
                if (st.find(tmp)==st.end()) {
                    st.insert(tmp);
                    pq.push(tmp);
                }
            }
            i++;
        }

        for (auto i:res) {
            cout << i << " ";
        }
        cout << endl;
        return res[n-1];
    }
    int nthUglyNumber(int n) {
        if (n==1) {
            return 1;
        }
        vector<int> nums(n,0);
        nums[0]=1;
        int i2=0,i3=0,i5=0;
        int min_num;
        for (int i=1;i<n;i++) {
            min_num = min(min(nums[i2]*2,nums[i3]*3), nums[i5]*5);
            nums[i] = min_num;
            if (min_num==nums[i2]*2) {
                i2++;
            }
            if (min_num==nums[i3]*3) {
                i3++;
            }
            if (min_num==nums[i5]*5) {
                i5++;
            }
        }

        for (auto i:nums) {
            cout << i << " ";
        }
        cout << endl;

        return nums[n-1];
    }
};

int main() {
    Solution s;
    int ret = s.nthUglyNumber1(1407);

    cout << ret << endl;
    return 0;
}
