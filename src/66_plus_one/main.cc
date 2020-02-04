/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cc
* @author tanghaiyu777@163.com
* @date   2019/11/30
* @brief  
*
**/

#include <iostream>
#include <vector>

using std::vector;

class Solution {
    public:
        vector<int> plusOne(vector<int>& digits) {
            int n = digits.size();
            if (digits[n-1] + 1 < 9) {
                digits[n-1] = digits[n-1] + 1;
            } else {
                int carry = 1;
                int num = 0;
                vector<int>::reverse_iterator it;
                for (it = digits.rbegin(); it != digits.rend(); ++it) {
                    num = *it + carry;
                    if (num <= 9){
                        *it = num;
                        carry = 0;
                    } else {
                        *it = num % 10;
                        carry = 1;
                    }
                }

                if (carry == 1) {
                    digits.insert(digits.begin(), carry);
                }

            }
            return digits;
        }

};


int main() {

    vector<int> nums;

    nums.push_back(9);
    nums.push_back(9);
    nums.push_back(9);

    Solution s;

    vector<int> ret = s.plusOne(nums);

    for (vector<int>::iterator it = ret.begin(); it != ret.end(); ++it) {
        std::cout<<*it<<std::endl;
    }

}
