/***************************************************************************
*
* Copyright (c) Tang Haiyu. All Rights Reserved
*
***************************************************************************/

/**
* @file   main.cpp
* @author tanghaiyu777@163.com
* @date   2018/03/21
* @brief  
*
**/

#include <cstdio>
#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool comp_func(Interval a, Interval b) {
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.size() == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), comp_func);
        for (int i = 0; i < intervals.size(); i++) {
            if (i+1 < intervals.size()) {
                if (intervals[i+1].start <= intervals[i].end) {
                    if (intervals[i+1].end > intervals[i].end) {
                        intervals[i+1].start = intervals[i].start;
                    } else {
                        intervals[i+1] = intervals[i];
                    }
                } else {
                    res.push_back(intervals[i]);
                }
            }
            printf("i:%d %d i+1:%d %d\n",
                    intervals[i].start, intervals[i].end,
                    intervals[i+1].start, intervals[i+1].end);
        }
        res.push_back(intervals[intervals.size() - 1]);
        return res;
    }
};

int main() {
    Solution s;
    vector<Interval> intervals;
    vector<Interval> res;
    //[[3,3],[1,1],[0,2],[2,2],[1,2],[1,3],[1,1],[3,3],[2,3],[4,6]]
    intervals.push_back(Interval(3, 3));
    intervals.push_back(Interval(1, 1));
    intervals.push_back(Interval(0, 2));
    intervals.push_back(Interval(2, 2));
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(1, 1));
    intervals.push_back(Interval(3, 3));
    intervals.push_back(Interval(2, 3));
    intervals.push_back(Interval(4, 6));
    res = s.merge(intervals);
    for (int i = 0; i < res.size(); i++) {
        printf("%d %d\n", res[i].start, res[i].end);
    }

    return 0;
}
