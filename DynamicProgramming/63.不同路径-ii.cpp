/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (32.59%)
 * Likes:    247
 * Dislikes: 0
 * Total Accepted:    49.1K
 * Total Submissions: 150.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <iostream>
#define MAXSIZE 100
using namespace std;
class Solution
{
public:
    long memory[MAXSIZE][MAXSIZE] = {0}; //! trivial in dp
    int dp_bottom_up(int m, int n, vector<vector<int>> &obstacleGrid)
    {
        for (size_t i = 1; i < m; i++)
        {
            for (size_t j = 1; j < n; j++)
            {
                memory[i][j] = obstacleGrid[i][j] ? 0 : (memory[i - 1][j] + memory[i][j - 1]);
            }
        }

        return memory[m - 1][n - 1];
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //* init dp
        memory[0][0] = !obstacleGrid[0][0];
        for (size_t i = 1; i < m; i++)
        {
            memory[i][0] = (memory[i - 1][0] == 0 || obstacleGrid[i][0]) ? 0 : 1;
        }
        for (size_t i = 1; i < n; i++)
        {
            memory[0][i] = (memory[0][i - 1] == 0 || obstacleGrid[0][i]) ? 0 : 1;
        }

        return dp_bottom_up(m, n, obstacleGrid); //* 2-d DP
    }
};
// @lc code=end

/*
1. understand the mearning of m,n, memory before you write(which is row, column)
2. memory[i][j] means the number of paths from 0,0 to i,j
*/