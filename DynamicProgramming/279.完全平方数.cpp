/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <cmath>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        int sqaure = sqrt(n) + 1;
        vector<int> sqaures;
        for (size_t i = 0; i < sqaure; i++)
        {
            sqaures.push_back(pow(i, 2));
        }
    }
};
// @lc code=end
