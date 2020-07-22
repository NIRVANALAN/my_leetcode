/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.size() + s2.size() != s3.size())
            return false;
        // bool dp[s1.size() + 1][s2.size() + 1];
        // auto dp = vector<vector<int>>{s1.size() + 1, vector<int>(s2.size() + 1, false)};
        // todo - scroll array
        auto dp = vector<int>(s2.size() + 1, false);
        dp[0] = true;
        // dp[0][0] = true;
        for (size_t i = 0; i <= s1.size(); i++)
        {
            for (size_t j = 0; j <= s2.size(); j++)
            {
                if (i > 0)
                    //     dp[i][j] |= dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                    dp[j] &= s1[i - 1] == s3[i + j - 1]; //? attention
                if (j > 0)
                    // dp[i][j] |= dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
                    dp[j] |= dp[j - 1] && s2[j - 1] == s3[i + j - 1];
            }
        }
        return dp[s2.size()];
    }
};
// @lc code=end
