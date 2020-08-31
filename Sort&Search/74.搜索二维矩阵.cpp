/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (!matrix.size() || !matrix[0].size())
            return false;
        int len1 = matrix.size(), len2 = matrix[0].size();
        int l = 0, r = len1 * len2 - 1;
        while (l < r)
        {
            int m = (l + r) >> 1; //TODO
            if (matrix[m / len2][m % len2] < target)
                l = m + 1;
            else
                r = m;
        }

        if (matrix[r / len2][r % len2] == target)
            return true;
        return false;
    }
};
// @lc code=end
