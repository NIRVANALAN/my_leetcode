/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
//* b search
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        // return bSearch(nums, nums[0]);
        int l = 0, r = nums.size() - 1, m;
        while (l < r) // no l<=r when no m++/m--
        {
            m = (l + r) >> 1;
            if (nums[m] > nums[r])
                l = m + 1;
            else
            {
                r = m; //* no -1 cause there is no comparision
            }
        }
        return nums[l];
    }
    int bSearch(vector<int> &nums, int target) //todo
    {
        int l = 1, r = nums.size() - 1, m;
        while (l <= r)
        {
            m = (l + r) >> 1;
            if (nums[m] > target)
                l = m + 1;
            else if (nums[m] < target)
            {
                target = nums[m];
                r = m - 1;
            }
        }
        return target;
    }
};
// @lc code=end
