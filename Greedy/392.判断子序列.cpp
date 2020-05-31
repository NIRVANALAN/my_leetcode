/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
#include <string>
using std::string;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        if (s.size() > t.size())
            return false;
        int s_ptr = 0, t_ptr = 0;
        for (; s_ptr < s.size(); s_ptr++, t_ptr++)
        {
            while (s[s_ptr] != t[t_ptr])
            {
                t_ptr++;
                if (t_ptr > t.size() - 1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
// @lc code=end
