/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution
{
public:
    string convert(string s, int numRows)
    {
        // numRows, numRows-2
        if (numRows == 1 || numRows >= s.size())
            return s;
        string ret;
        int adder = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++)
        {
            for (size_t j = 0; j + i < s.size(); j += adder)
            {
                ret += s[j + i];
                if (i != 0 && i != numRows - 1 && j + adder - i < s.size())
                    ret += s[j + adder - i];
            }
        }
        return ret;
        // 1. thinking global coherent index, rather than relying on the previous idx
        // 2. special cases
    }
};
// @lc code=end