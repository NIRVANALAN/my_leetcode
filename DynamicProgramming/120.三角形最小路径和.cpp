/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dp(triangle[triangle.size() - 1]);
        for (int i = triangle.size() - 2; i >= 0; i--)
        {
            for (size_t j = 0; j < triangle[i].size(); j++)
            {
                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }
        return dp[0];
        }
};
// @lc code=end

