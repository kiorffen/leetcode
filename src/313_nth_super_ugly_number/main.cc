/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/14
* @brief  
*
**/
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<long, vector<long>, greater<long>> pq;
        pq.push(1);
        vector<int> ans;
        set<long> st;
        st.insert(1);

        int tmp;
        for (int i=0;i<n;i++) {
            tmp = pq.top();
            pq.pop();
            ans.push_back(tmp);
            for (int j=0;j<primes.size();j++) {
                long t = (long)tmp*(long)primes[j];
                if (st.find(t)==st.end()) {
                    st.insert(t);
                    pq.push(t);
                }
            }
        }

        for (auto i:ans) {
            cout << i << " ";
        }
        cout << endl;

        return ans[n-1];

    }
    int nthSuperUglyNumber1(int n, vector<int>& primes) {
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> idx(primes.size(),0);
        int i = 1;
        while (i<n) {
            int minval = INT_MAX;
            for (int j=0;j<idx.size();j++) {
                int tmp = dp[idx[j]]*primes[j];
                if (minval>tmp) {
                    minval = tmp;
                }
            }

            for (int j=0;j<idx.size();j++) {
                if (minval == dp[idx[j]] * primes[j]) {
                    idx[j]++;
                }
            }
            dp[i] = minval;
            i++;
        }

        return dp[n-1];
    }
};

int main() {


    Solution s;

    vector<int> primes = {2,7,13,19};
    int ret = s.nthSuperUglyNumber1(12, primes);
    cout << ret << endl;

    return 0;
}
