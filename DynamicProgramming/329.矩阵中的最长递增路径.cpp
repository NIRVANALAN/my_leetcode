/*
 * @lc app=leetcode.cn id=329 lang=cpp
 *
 * [329] 矩阵中的最长递增路径
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    //* 记忆化深度优先搜索
public:
    int xIter[4] = {0, 1, 0, -1};
    int yIter[4] = {1, 0, -1, 0};
    int maxPath = 0;
    vector<vector<int>> f;
    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0 || matrix[0].size() == 0) //!
            return maxPath;
        f = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), 0)); //!
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                maxPath = max(maxPath, dp(i, j, matrix));
            }
        }
        return maxPath;
    }
    int dp(int i, int j, vector<vector<int>> &matrix)
    {
        if (f[i][j] == 0) //! not !f[i][j]
        {
            int flag = false;
            f[i][j] = 1;
            for (size_t k = 0; k < 4; k++)
            {
                int tmpX = i + xIter[k];
                int tmpY = j + yIter[k];
                if (tmpX >= 0 && tmpX < matrix.size() && tmpY >= 0 && tmpY < matrix[0].size() && matrix[tmpX][tmpY] > matrix[i][j])
                {
                    flag = true;
                    f[i][j] = max(f[i][j], dp(tmpX, tmpY, matrix) + 1); //* +1
                }
            }
        }
        return f[i][j];
    }
    //TODO: topology sort
};
/*
1.border
2.WA
[[0,1,2,3,4,5,6,7,8,9],[19,18,17,16,15,14,13,12,11,10],[20,21,22,23,24,25,26,27,28,29]]
*/
// @lc code=end
