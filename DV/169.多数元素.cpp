/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int countInRange(int l, int r, vector<int> &nums, int num)
    {
        int count = 0; //! initialize
        for (size_t i = l; i <= r; i++)
        {
            if (nums[i] == num)
                count++;
        }
        return count;
    }
    int majorityElementRec(vector<int> &nums, int l, int r)
    {
        if (l == r)
            return nums[r];
        int mid = (l + r) >> 1;
        int leftMajority = majorityElementRec(nums, l, mid);
        int rightMajority = majorityElementRec(nums, mid + 1, r); // ! +1
        if (countInRange(l, r, nums, leftMajority) > (r - l + 1) >> 1)
            return leftMajority;
        if (countInRange(l, r, nums, rightMajority) > (r - l + 1) >> 1)
            return rightMajority;
        return -1;
    }
    int majorityElement(vector<int> &nums)
    {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
};
// @lc code=end
