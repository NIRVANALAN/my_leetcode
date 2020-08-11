/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans = {-1, -1};
        int l = bSearch(nums, target, true);
        if (l == nums.size() || nums[l] != target)
            return ans;

        //* not applicable: O(N)
        // int l = pos, r = l;
        // while (l - 1 >= 0 && nums[l - 1] == target)
        //     l--;
        // while (r + 1 <= nums.size() - 1 && nums[r + 1] == target)
        //     r++;
        int r = bSearch(nums, target, false) - 1;
        ans[0] = l, ans[1] = r;
        return ans;
    }
    int bSearch(vector<int> nums, int target, bool left)
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (nums[mid] > target || (left && nums[mid] == target))
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};
// @lc code=end
