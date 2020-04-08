/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 *
 * https://leetcode-cn.com/problems/longest-common-subsequence/description/
 *
 * algorithms
 * Medium (58.68%)
 * Likes:    90
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 25.4K
 * Testcase Example:  '"abcde"\n"ace"'
 *
 * 给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列。
 * 
 * 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
 * 例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde"
 * 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
 * 
 * 若这两个字符串没有公共子序列，则返回 0。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入：text1 = "abcde", text2 = "ace" 
 * 输出：3  
 * 解释：最长公共子序列是 "ace"，它的长度为 3。
 * 
 * 
 * 示例 2:
 * 
 * 输入：text1 = "abc", text2 = "abc"
 * 输出：3
 * 解释：最长公共子序列是 "abc"，它的长度为 3。
 * 
 * 
 * 示例 3:
 * 
 * 输入：text1 = "abc", text2 = "def"
 * 输出：0
 * 解释：两个字符串没有公共子序列，返回 0。
 * 
 * 
 * 
 * 
 * 提示:
 * 
 * 
 * 1 <= text1.length <= 1000
 * 1 <= text2.length <= 1000
 * 输入的字符串只含有小写英文字符。
 * 
 * 
 */
#include <iostream>
#include <string>
#define maxsize 1000
using namespace std;
// @lc code=start
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        if (text1.size() == 0 || text2.size() == 0)
            return 0;
        //dp
        int dp[text1.size()][text2.size()];
        for (size_t i = 0; i < text1.size(); i++)
            for (size_t j = 0; j < text2.size(); j++)
                dp[i][j] = 0;

        //init
        dp[0][0] = text1[0] == text2[0];
        for (size_t i = 1; i < text2.size(); i++)
        {
            if (text1[0] == text2[i])
                dp[0][i] = 1;
            else
                dp[0][i] = dp[0][i - 1];
        }
        for (size_t i = 1; i < text1.size(); i++)
        {
            if (text2[0] == text1[i])
                dp[i][0] = 1;
            else
                dp[i][0] = dp[i - 1][0];
        }
        //recursion
        for (size_t i = 1; i < text1.size(); i++)
        {
            for (size_t j = 1; j < text2.size(); j++)
            {
                if (text1[i] == text2[j])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[text1.size() - 1][text2.size() - 1];
    }
};
// @lc code=end
