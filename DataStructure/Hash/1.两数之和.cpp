/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> hash;
        vector<int> ans;

        for (size_t i = 0; i < nums.size(); i++)
        {
            if (hash.find(target - nums[i]) != hash.end())
            {
                ans.push_back(hash[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            hash.insert(pair<int, int>(nums[i], i));
        }
        return ans;
    }
};
// @lc code=end
