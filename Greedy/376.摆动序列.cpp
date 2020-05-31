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
        bool pos = false, neg = false;
        int rst = 1;

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1] && !pos)
            {
                pos = true;
                neg = false;
                // neg = !neg;
                rst++;
            }
            else if (nums[i] < nums[i - 1] && !neg)
            {
                neg = true;
                pos = false;
                rst++;
            }
        }
        return rst;

        // for (i += 1; i < nums.size(); i++)
        // {
        //     if (nums[i] == nums[i - 1])
        //         continue;
        //     if (bool(nums[i] > tmp) == flag)
        //     {
        //         rst += 1;
        //         flag = !flag;
        //         tmp = nums[i];
        //         cout << tmp << " ";
        //     }
        // }
    }
};
// @lc code=end
