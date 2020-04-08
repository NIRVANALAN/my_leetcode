/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <iostream>
#include <string>
#define maxsize 1000
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        //init
        int dp[s.size()][s.size()];
        for (size_t i = 0; i < s.size(); i++)
            for (size_t j = 0; j < s.size(); j++)
                dp[i][j] = i == j;

        for (int i = s.size() - 2; i >= 0; i--)
            for (size_t j = i + 1; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j == i + 1)
                        dp[i][j] = 2;
                    else
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }

        return dp[0][s.size() - 1];
    }
};
// @lc code=end
