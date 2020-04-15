/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int ret = 0;
        stack<int> s;
        heights.push_back(0);
        heights.insert(heights.begin(), 0); //! sentinal
        for (int i = 0; i < heights.size(); i++)
        {
            while (!s.empty() && heights[i] < heights[s.top()])
            {
                auto tmp = s.top();
                s.pop();
                ret = max(ret, heights[tmp] * (i - 1 - s.top())); //* s.top() always nonzero because of sentinal
            }
            s.push(i);
        }
        return ret;
    }
};
// @lc code=end
