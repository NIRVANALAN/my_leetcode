/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int rotatePoint = binarySearch(nums, 0, nums.size() - 1);
        vector<int>::iterator index;
        if (target > nums[nums.size() - 1])
            index = lower_bound(nums.begin(), nums.begin() + rotatePoint, target);
        else
            index = lower_bound(nums.begin() + rotatePoint, nums.end(), target);
        int dist = distance(nums.begin(), index);
        if (index == nums.end() || target != nums[dist])
            return -1;
        return dist;
    }
    int binarySearch(vector<int> &nums, int l, int r)
    {
        while (l < r)
        {
            int m = (l + r) >> 1;
            if (nums[m] > nums[r])
                l = m + 1;
            else if (nums[m] < nums[r])
                r = m;
            else
                r--; // remove duplicates
        }
        return l;
    }
};
// @lc code=end
