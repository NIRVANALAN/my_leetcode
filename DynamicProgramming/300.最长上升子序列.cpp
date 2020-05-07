/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <algorithm>
using std::max;
using std::vector;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (!nums.size())
            return 0;
        vector<int> dp(nums.size()); // nums.size() copies of initialized value
        dp[0] = 1;
        for (size_t i = 1; i < nums.size(); i++)
        {
            for (size_t j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += 1;
        }
        return *std::max_element(dp.begin(), dp.end());
    }
};
// @lc code=end
