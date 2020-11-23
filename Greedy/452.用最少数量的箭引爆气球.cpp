/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */
#include <bits/stdc++.h>
#include <queue>
using namespace std;
// @lc code=start
class Solution
{
    //greedy, sort
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        if (points.size() <= 1)
            return points.size();
        sort(points.begin(), points.end(), [](const vector<int> u, const vector<int> v) {
            return u[1] < v[1];
        });
        int ans = 1;
        auto border = points[0][1];
        for (auto &bollon : points)
        {
            if (bollon[0] > border)
            {
                border = bollon[1];
                ans++;
            }
        }

        return ans;
    }
};
// @lc code=end
/*
1. sort with right border or left border
2. no '-' in sorting comparision
*/