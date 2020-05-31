/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::cout;
using std::vector;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();

        size_t i = 1;
        while (i < nums.size() && nums[i] == nums[i - 1])
            i++;

        if (i == nums.size())
            return 1;

        auto flag = nums[0] > nums[i];
        int rst = 2;
        int tmp = nums[i];

        for (i += 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
                continue;
            if (bool(nums[i] > tmp) == flag)
            {
                rst += 1;
                flag = !flag;
                tmp = nums[i];
            }
        }
        return rst;
    }
};
// @lc code=end
