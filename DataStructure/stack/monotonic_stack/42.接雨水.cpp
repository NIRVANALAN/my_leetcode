/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using std::cout;
using std::min;
using std::stack;
using std::vector;
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int res = 0, previous_top = 0;
        stack<int> s; // decreasing monoStack
        for (int i = 0; i < height.size(); i++)
        {
            while (!s.empty() && height[i] >= height[s.top()])
            {
                previous_top = s.top();
                s.pop();
                while (!s.empty() && height[s.top()] == height[previous_top])
                    s.pop(); //* remvoe redundant idx
                if (!s.empty())
                {
                    res += (i - s.top() - 1) * (min(height[i], height[s.top()]) - height[previous_top]); //* handle a row
                    // cout << i << " " << s.top() << " " << res << std::endl;
                }
            }
            s.push(i);
        }
        return res;
    }
};
// @lc code=end
