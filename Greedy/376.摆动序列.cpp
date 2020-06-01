/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::vector;
class Solution
{
public:
    int wiggleMaxLength(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        string flag;
        int rst = 1;

        for (size_t i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1] && (!flag.compare("neg") || !flag.size()))
            {
                flag = "pos";
                rst++;
            }
            else if (nums[i] < nums[i - 1] && (!flag.compare("pos") || !flag.size()))
            {
                flag = "neg";
                rst++;
            }
        }
        return rst;
    }
};
// @lc code=end
