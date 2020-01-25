/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 *
 * https://leetcode-cn.com/problems/container-with-most-water/description/
 *
 * algorithms
 * Medium (60.63%)
 * Likes:    1060
 * Dislikes: 0
 * Total Accepted:    127.7K
 * Total Submissions: 210.4K
 * Testcase Example:  '[1,8,6,2,5,4,8,3,7]'
 *
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为
 * (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 
 * 说明：你不能倾斜容器，且 n 的值至少为 2。
 * 
 * 
 * 
 * 图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [1,8,6,2,5,4,8,3,7]
 * 输出: 49
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1, max_volume = -1, current_volume = 0;
        while (i != j)
        {
            current_volume = min(height[i], height[j]) * (j - i);
            if (current_volume > max_volume)
                max_volume = current_volume;
            height[i] >= height[j] ? j-- : i++;
        }
        return max_volume;
    }
};
// @lc code=end
