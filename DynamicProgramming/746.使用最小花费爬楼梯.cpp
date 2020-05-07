/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution
{
public:
    int dp[1000] = {0};
    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(recursion(cost, 0), recursion(cost, 1));
    }
    int recursion(vector<int> &cost, int i)
    {
        if (i >= cost.size())
            return 0;
        if (!dp[i])
            dp[i] = cost[i] + min(recursion(cost, i + 2), recursion(cost, i + 1));
        return dp[i];
    }
};
// @lc code=end
