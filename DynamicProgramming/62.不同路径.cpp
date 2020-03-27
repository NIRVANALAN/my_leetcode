/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (59.63%)
 * Likes:    462
 * Dislikes: 0
 * Total Accepted:    85.4K
 * Total Submissions: 143.2K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 * 
 * 
 */

// @lc code=start
using namespace std;
#define MAXSIZE 101
#include <iostream>
class Solution
{
public:
    int memory[MAXSIZE][MAXSIZE] = {0};
    int dp_top_down_memorization(int m, int n)
    {

        if (memory[m][n] >= 0)
            return memory[m][n];
        memory[n][m] = memory[m][n] = dp_top_down_memorization(m - 1, n) + dp_top_down_memorization(m, n - 1);
        // cout << m << " " << n << " " << memory[m][n] << endl;
        return memory[m][n];
    }
    int dp_bottom_up(int m, int n)
    {
        for (size_t i = 2; i <= m; i++)
        {
            for (size_t j = 2; j <= n; j++)
            {
                if (memory[i][j] >= 0)
                    continue;
                memory[j][i] = memory[i][j] = memory[i - 1][j] + memory[i][j - 1];
            }
        }
        return memory[m][n];
    }
    int uniquePaths(int m, int n)
    {
        if (m == n && m == 1) //! no m==n==1
            return 1;
        for (size_t i = 0; i < MAXSIZE; i++)
        {
            for (size_t j = 0; j < MAXSIZE; j++)
            {
                memory[i][j] = -1;
            }
            memory[1][i] = 1;
            memory[i][1] = 1;
        }
        memory[1][1] = 0;
        // return dp_top_down_memorization(m, n);
        return dp_bottom_up(m, n);
    };
};

// int main(int argc, char const *argv[])
// {

//     auto s = new Solution();
//     cout << s->uniquePaths(3, 3);
//     return 0;
// }

// @lc code=end
