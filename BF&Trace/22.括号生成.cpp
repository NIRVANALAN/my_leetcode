/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> rst;
        string current;
        bruteforce_recursion(n, rst, current, 0, 0);
        return rst;
    }
    void bruteforce_recursion(int n, vector<string> &rst, string &current, int open, int close)
    { // TODO
        // cout << current << endl;
        if (n == current.size())
        {
            // cout << current << open << endl;
            if (close == open == n && valid_parenthesis(current))
                rst.push_back(current); // ?problem on reference?
            return;
        }
        if (open < n)
        {
            current.push_back('(');
            bruteforce_recursion(n, rst, current, open + 1, close);
            current.pop_back();
        }

        if (n > open > close)
        {
            current.push_back(')');
            bruteforce_recursion(n, rst, current, open, close + 1);
            current.pop_back();
        }
    }
    bool valid_parenthesis(string s)
    {
        auto stack = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stack++;
            else
            {
                stack--; //! pop first!
                if (stack < 0)
                    return false;
            }
        }
        return stack == 0;
    }
};

// int main(int argc, char const *argv[])
// {
//     string s = ")()()(";

//     auto solu = new Solution();
//     auto rst = solu->valid_parenthesis(s);
//     cout << rst;
//     return 0;
// }

// @lc code=end
