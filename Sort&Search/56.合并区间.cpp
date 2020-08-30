/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    static bool compIntervals(vector<int> a, vector<int> b)
    {
        return a[0] < b[0]; //slow
    }
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.size() <= 1)
            return intervals;
        //sort todo
        // sort(intervals.begin(), intervals.end(), compIntervals);
        sort(intervals.begin(), intervals.end(), [](const vector<int> &o1, const vector<int> &o2) { return (o1[0] < o2[0]); });
        vector<vector<int>> mergedIntervals{intervals[0]};
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (mergedIntervals.back()[1] >= intervals[i][0]) //merge
            {
                if (mergedIntervals.back()[1] < intervals[i][1])
                    mergedIntervals.back()[1] = intervals[i][1];
                else
                    continue;
            }
            else
            {
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};
// @lc code=end
