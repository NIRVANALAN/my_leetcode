/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() < 1)
            return 0;
        for (size_t i = 1; i < grid.size(); i++)
        {
            grid[i][0] += grid[i - 1][0];
        }
        for (size_t i = 1; i < grid[0].size(); i++)
        {
            grid[0][i] += grid[0][i - 1];
        }

        for (size_t i = 1; i < grid.size(); i++)
        {
            for (size_t j = 1; j < grid[0].size(); j++)
            {
                grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end
