/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        return bSearch(nums, 0, nums.size() - 1);
    }
    int bSearch(vector<int> &nums, int l, int r)
    {
        // return bSearch(nums, nums[0]);
        int m;
        while (l < r) // no l<=r when no m++/m--
        {
            m = (l + r) >> 1;
            if (nums[m] > nums[r])
                l = m + 1;
            else if (nums[m] < nums[r])
            {
                r = m; //* no -1 cause there is no comparision
            }
            else
            {
                // return min(bSearch(nums, l, m), bSearch(nums, m + 1, r)); //* me
                r--; // get pivot
            }
        }
        return nums[l];
    }
};
// @lc code=end
