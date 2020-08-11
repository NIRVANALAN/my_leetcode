/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        // return bSearch(nums, 0, nums.size() - 1);
        if (nums.size() == 1)
            return 0;
        nums.push_back(INT_MIN);
        int step = nums.size() / 2, i = step;
        while (i > 0 && (nums[i] < nums[i - 1] || nums[i] < nums[i + 1]))
        {
            step = max(1, step / 2);
            if (nums[i] > nums[i - 1])
                i += step;
            else
                i -= step;
        }
        return i;
    }
    // bSearch
    int bSearch(vector<int> nums, int l, int r)
    {
        if (l == r)
            return l;
        // int mid = (l + r) >> 1;
        int mid = (l + r) / 2;
        if (nums[mid] > nums[mid + 1]) //(l+r)/2 lower_bound
            return bSearch(nums, l, mid);
        return bSearch(nums, mid + 1, r);
    }
    int bSearchIter(vector<int> nums, int l, int r)
    {
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] < nums[mid + 1])
            {
                l = mid + 1;
            }
            else
                r = mid;
        }
        return l;
    }
};
// @lc code=end