/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int prev_sum = 0, tmp = 0, rest = 0, start = 0;
        for (size_t i = 0; i < gas.size(); i++)
        {
            tmp = gas[i] - cost[i];
            prev_sum += tmp;
            rest += tmp;
            if (prev_sum < 0)
            {
                prev_sum = 0;
                start = i + 1;
            }
        }
        return rest >= 0 ? start : -1;
    }
};
// @lc code=end
