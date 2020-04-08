/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <iostream>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        // return dp(s);
        return expand_center(s);
    }
    string expand_center(string s)
    {
        if (s == "" || s.size() == 1) //! border
            return s;
        string rst = s.substr(0, 1);
        int left, right, low = 0, length = 1; //!initialize
        //1d
        for (size_t i = 1; i < s.size(); i++)
        {
            left = i - 1, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) //>=0 as border
            {
                if (right - left + 1 > length)
                    low = left, length = right - left + 1;
                left--;
                right++;
            }
        }
        //2d
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == s[i + 1])
            {
                if (length < 2)
                    low = i, length = 2;
                left = i - 1, right = i + 2;
                while (left >= 0 && right < s.size() && s[left] == s[right])
                {
                    if (right - left + 1 > length)
                        low = left, length = right - left + 1;
                    // rst = s.substr(left, right - left + 1);
                    left--;
                    right++;
                }
            }
        }

        return s.substr(low, length);
    }
    string dp(string s)
    {

        int size = s.size();
        if (s == "" || size == 1)
            return s;
        bool dp[1000][1000] = {false}; //! fuck
        string rst = s.substr(0, 1);
        //1+2d longestPalindrome
        for (int i = 0; i < size; i++)
        {
            dp[i][i] = 1;
            if (i < size && s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                rst = s.substr(i, 2);
            }
        }
        for (int i = size - 2; i >= 0; i--)
            for (int j = i + 1; j < size; j++)
            {
                if (j != i + 1)
                    dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
                if (dp[i][j] && (j - i + 1) > rst.size())
                {
                    rst = s.substr(i, j - i + 1);
                }
            }
        return rst;
    }
};
// @lc ckde=end
