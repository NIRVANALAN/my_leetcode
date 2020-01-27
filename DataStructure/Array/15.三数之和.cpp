/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (25.12%)
 * Likes:    1725
 * Dislikes: 0
 * Total Accepted:    146K
 * Total Submissions: 580.3K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 
 * 
 * 示例：
 * 
 * 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using std::sort;
using std::vector;
class Solution
{
public:
    static bool comp(int i, int j) { return i < j; }
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        if (nums.size() < 3)
            return vector<vector<int>>();
        sort(nums.begin(), nums.end());
        if (nums.front() > 0 || nums.back() < 0)
            return vector<vector<int>>();
        vector<vector<int>> ret;
        int L, R, res;
        for (auto i = 0; nums[i] <= 0 && i<nums.size()-2; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            L = i + 1, R = nums.size() - 1;
            while (L < R)
            {
                res = nums[i] + nums[L] + nums[R];
                if (res == 0)
                {
                    ret.push_back(vector<int>{nums[i], nums[L], nums[R]});
                    do
                    {
                        R--;
                    } while (L < R && nums[R] == nums[R + 1]); // ! compare with original R 

                    do
                    {
                        L++;
                    } while (L < R && nums[L] == nums[L - 1]);
                }
                else // move pointer
                {
                    res > 0 ? R-- : L++; // ! use implicit res>0
                }
            }
        }
        return ret;
    }
};

// int main(int argc, char const *argv[])
// {
//     vector<int> nums{-1, -1, 0, 1};
//     auto s = Solution();
//     auto res = s.threeSum(nums);
//     // for (auto i : res)
//     // {
//     //     for (auto &&j : i)
//     //     {
//     //         std::cout << j;
//     //     }
//     //     std::cout << std::endl;
//     // }

//     return 0;
// }

// @lc code=end
