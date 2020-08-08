/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // return binarySearch(nums, target);
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
    int binarySearch(vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        while (l <= r) //?
        {
            int m = (l + r) >> 1;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                r = m - 1;
            else
                l = m + 1;
        }
        // return index here
        // return r < l ? l : max(0, r);
        return l;
    }
};
// @lc code=end
