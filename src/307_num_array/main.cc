/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2020/03/08
* @brief  
*
**/

#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        if (nums.size() > 0) {
            n=nums.size();
            tree.resize(2*n);
            buildTree(nums);
        }
    }

    void buildTree(vector<int>& nums) {
        for (int i=n,j=0;i<2*n;i++,j++) {
            tree[i] = nums[j];
        }
        for (int i=n-1;i>0;--i) {
            tree[i]=tree[i*2]+tree[i*2+1];
        }
    }
    
    void update(int i, int val) {
        int pos = i+n;
        tree[pos] = val;
        while (pos>0) {
            int left=pos;
            int right=pos;
            if (pos%2==0) {
                right =pos+1;
            } else {
                left=pos-1;
            }
            tree[pos/2] = tree[left] + tree[right];
            pos/=2;
        }
    }
    
    int sumRange(int i, int j) {
        int l=i+n;
        int r=j+n;
        int sum=0;
        while (l<=r) {
            if (l%2==1) {
                sum+=tree[l];
                l++;
            }
            if (r%2==0) {
                sum+=tree[r];
                r--;
            }
            l/=2;
            r/=2;
        }

        return sum;
    }
};

int main() {
    vector<int> nums={2,4,5,7,8,9};
    NumArray* obj=new NumArray(nums);
    int ret = obj->sumRange(1,4);
    cout << ret << endl;

    return 0;
}
