/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <algorithm>
#define maxlen 1000
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        // vector<int> maxF(nums), minF(nums);
        int minf, maxf, rst, mx;
        minf = maxf = rst = nums[0];
        for (size_t i = 1; i < nums.size(); i++)
        {
            mx = maxf; //! mx is the previous value of maxf, cannot be modified here
            maxf = max(nums[i], max(maxf * nums[i], minf * nums[i]));
            minf = min(nums[i], min(mx * nums[i], minf * nums[i]));
            rst = max(rst, maxf);
        }
        return rst;
    }
};
// @lc code=end
