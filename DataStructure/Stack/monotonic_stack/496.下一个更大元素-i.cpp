/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
    map<int, int> hashmap;
    stack<int> monotonic_stack;
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        if (!nums1.size())
            return nums1;
        for (size_t i = 0; i < nums2.size(); i++)
        {
            while (monotonic_stack.size() && monotonic_stack.top() < nums2[i])
            {
                hashmap.insert(pair<int, int>(monotonic_stack.top(), nums2[i]));
                monotonic_stack.pop();
            }
            monotonic_stack.push(nums2[i]);
        }
        while (monotonic_stack.size())
        {
            hashmap.insert(pair<int, int>(monotonic_stack.top(), -1));
            monotonic_stack.pop();
        }
        for (size_t i = 0; i < nums1.size(); i++)
        {
            nums1[i] = hashmap.find(nums1[i])->second;
        }
        return nums1;
    }
};
// @lc code=end
