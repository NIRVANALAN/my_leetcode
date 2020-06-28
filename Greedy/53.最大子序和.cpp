/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // return maxArrayHelper(nums, 0, nums.size() - 1);
        int prefix_subarray_sum = 0, ans = INT_MIN; // sum of array end with i
        for (auto &&i : nums)
        {
            prefix_subarray_sum += i;
            ans = max(ans, prefix_subarray_sum);
            if (prefix_subarray_sum < 0)
                prefix_subarray_sum = 0;
        }
        return ans;
    }
    int maxArrayHelper(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];
        int mid = (right + left) / 2;
        int rst = findCrossingMaxArray(nums, mid, left, right);
        return max(max(maxArrayHelper(nums, left, mid), maxArrayHelper(nums, mid + 1, right)), rst);
    }
    int findCrossingMaxArray(vector<int> &nums, int mid, int left, int right)
    {

        int left_max = INT_MIN, right_max = INT_MIN, tmp = 0; //!
        for (size_t i = mid + 1; i <= right; i++)
        {
            tmp += nums[i];
            right_max = max(tmp, right_max);
        }
        tmp = 0;
        for (int i = mid; i >= left; i--) //! mid merged into left
        {
            tmp += nums[i];
            left_max = max(left_max, tmp);
        }
        return left_max + right_max;
    }
};
// @lc code=end
