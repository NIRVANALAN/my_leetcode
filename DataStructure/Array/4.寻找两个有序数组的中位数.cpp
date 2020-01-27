/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (36.60%)
 * Likes:    2062
 * Dislikes: 0
 * Total Accepted:    134.5K
 * Total Submissions: 367.6K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int median_idx = (nums1.size() + nums2.size()) / 2, l1 = 0, l2 = 0;
        float ans;
        while (l1 < nums1.size() && l2 < nums2.size() && (l1 + l2) < median_idx)
        {
            (nums1[l1] <= nums2[l2]) ? ans = nums1[l1++] : ans = nums1[l2++];
        }
        if (l1==nums1.size())
        {
            if ((l1+l2)==median_idx)
            {
                (median_idx % 2) ? ans = ans : ans = (ans + nums2[l2]) / 2;
            }
            
        }
        
        if ((l1 + l2) == median_idx)
        {
            if (median_idx % 2)
            {
                ans = min(nums1[l1], nums2[l2]);
            }
            else
            {
                ans = (ans + min(nums1[l1], nums2[l2]));
            }
        }
        else //
        {
        }

        // if (median_idx % 2)
        // {
        //     if (l1 == nums1.size())
        //         ans = nums2[l2];
        //     else if (l2 == nums2.size())
        //         ans = nums1[l1];
        //     else
        //         ans = min(nums1[l1], nums2[l2]);
        // }

        // else
        // {
        //     if (l1 == nums1.size())
        //         ans = (nums2[l2] + nums2[l2 + 1]) / 2;
        //     else if (l2 == nums2.size())
        //         ans = (nums1[l1] + nums1[l1 + 1]) / 2;
        //     else
        //         ans = (min(nums1[l1], nums2[l2]) + ans) / 2;
        // }
        return ans;
    }
};
// int main(int argc, char const *argv[])
// {
//     return 0;
// }

// @lc code=end
