/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int n = nums.size();
        vector<vector<long long>> dp = {nums.size() + 1, vector<long long>(m + 1, __LONG_LONG_MAX__)};
        vector<long long> sub(nums.size() + 1, 0);
        for (size_t i = 0; i < n; i++)
            sub[i + 1] = sub[i] + nums[i];

        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (size_t j = 1; j <= min(i, m); j++)
            {
                for (size_t k = 0; k < i; k++)
                    dp[i][j] = min(max(dp[k][j - 1], sub[i] - sub[k]), dp[i][j]);
            }
        }
        return (int)dp[n][m];
    }
};
// @lc code=end
