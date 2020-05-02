/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.70%)
 * Likes:    927
 * Dislikes: 0
 * Total Accepted:    110.9K
 * Total Submissions: 147.6K
 * Testcase Example:  '3'
 *
 * 数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
 * 
 * 
 * 
 * 示例：
 * 
 * 输入：n = 3
 * 输出：[
 * ⁠      "((()))",
 * ⁠      "(()())",
 * ⁠      "(())()",
 * ⁠      "()(())",
 * ⁠      "()()()"
 * ⁠    ]
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
    }
    bool validate(string s)
    {
        stack<char> p_stack;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                p_stack.push(s[i]);
            else
            {
                if (p_stack.size() == 0)
                    return false;
                p_stack.pop();
            }
        }
        if (p_stack.size() == 0)
            return true;
        return false;
    }
};
// @lc code=end
