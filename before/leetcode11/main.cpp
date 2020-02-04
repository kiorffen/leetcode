/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/08
* @brief  
*
**/
#include <cstdio>
#include <algorithm>
#include <vector>

using std::vector;
using std::max;
using std::min;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int max_area = 0;
            int left = 0;
            int right = height.size() - 1;
            int h = 0;

            while (left < right) {
                h = min(height[left], height[right]);
                max_area = max(max_area, (right - left)*h);
                while (left < right && height[left] <= h) {
                    left++;
                }
                while (left < right && height[right] <= h){
                    right--;
                }
            }
            return max_area;
        }
};


int main() {
    Solution s;
    vector<int> height;
    height.push_back(2);
    height.push_back(3);
    height.push_back(1);
    height.push_back(5);
    height.push_back(7);

    int max_area = s.maxArea(height);
    printf("%d\n", max_area);

    return 0;
}
