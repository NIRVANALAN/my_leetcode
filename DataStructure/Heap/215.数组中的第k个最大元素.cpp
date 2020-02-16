/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 *
 * https://leetcode-cn.com/problems/kth-largest-element-in-an-array/description/
 *
 * algorithms
 * Medium (60.45%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    71.8K
 * Total Submissions: 118.6K
 * Testcase Example:  '[3,2,1,5,6,4]\n2'
 *
 * 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 
 * 示例 1:
 * 
 * 输入: [3,2,1,5,6,4] 和 k = 2
 * 输出: 5
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
 * 输出: 4
 * 
 * 说明: 
 * 
 * 你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
 * 
 */

// @lc code=start
#include <vector>
#include <random>
using namespace std;
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int k_smallest = nums.size() - k;
        return quick_select_sort(0, nums.size() - 1, k_smallest, nums);
    }
    int partition(int left, int right, int pivot_index, vector<int> &nums)
    {
        auto pivot = nums[pivot_index];
        auto store_index = left;
        swap(nums[pivot_index], right);
        for (auto i = left; i <= right; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[store_index]);
                store_index++;
            }
        }
        swap(nums[store_index], nums[right]);
        return store_index; // smaller elements on the left
    }
    int quick_select_sort(int left, int right, int k_smallest, vector<int> &nums)
    {
        if (left==right)
            return nums[left];
        std::uniform_int_distribution<> pivot_generator(left, right - 1);
        std::default_random_engine random(time(NULL));
        int rand_pivot_index = pivot_generator(random);
        int partition_index = partition(left, right, 0, nums);
        if (partition_index == k_smallest)
            return nums[k_smallest];
        else if (partition_index < k_smallest)
            return quick_select_sort(partition_index + 1, right, k_smallest, nums);
        return quick_select_sort(left, partition_index, k_smallest, nums);
    }
};
// @lc code=end
