/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 *
 * https://leetcode-cn.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (51.18%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 16.6K
 * Testcase Example:  '[1,2,1]'
 *
 * 给定一个循环数组（最后一个元素的下一个元素是数组的第一个元素），输出每个元素的下一个更大元素。数字 x
 * 的下一个更大的元素是按数组遍历顺序，这个数字之后的第一个比它更大的数，这意味着你应该循环地搜索它的下一个更大的数。如果不存在，则输出 -1。
 * 
 * 示例 1:
 * 
 * 
 * 输入: [1,2,1]
 * 输出: [2,-1,2]
 * 解释: 第一个 1 的下一个更大的数是 2；
 * 数字 2 找不到下一个更大的数； 
 * 第二个 1 的下一个最大的数需要循环搜索，结果也是 2。
 * 
 * 
 * 注意: 输入数组的长度不会超过 10000。
 * 
 */

// @lc code=start
#include <vector>
#include <stack>
#include <iostream>
using std::stack;
using std::vector;
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        stack<int> monotic_stack;
        vector<int> res(nums.size(), -1);
        if (!res.size())
        {
            return res;
        }

        for (auto i = 0; i < nums.size() * 2 - 1; i++)
        {
            while (!monotic_stack.empty() && nums[i % nums.size()] > nums[monotic_stack.top()])
            {
                res[monotic_stack.top()] = nums[i % nums.size()];
                monotic_stack.pop();
            }
            // res[i % nums.size()] = monotic_stack.empty() ? -1 : nums[monotic_stack.top()];
            // * push index rather than value
            monotic_stack.push(i % nums.size());
            // std::cout << nums[monotic_stack.top()] << res[i % nums.size()] << std::endl;
        }
        return res;
    }
};
// ! zero case []
/*
224/224 cases passed (40 ms)
Your runtime beats 98.36 % of cpp submissions
Your memory usage beats 12.64 % of cpp submissions (14.2 MB)
*/

// @lc code=end
