/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=          start
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        if (nums.size() == 1)
            return nums;

        // typedef pair<int, int> dict;
        using dict = pair<int, int>;
        // map<int, int> counter;
        unordered_map<int, int> counter; //* much faster
        for (auto &&i : nums)
        {
            counter[i]++;
        }

        //* operator[] will assign default constructed value(0) if no key find
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        // if (hash.find(nums[i]) == hash.end())
        //     hash[nums[i]] = 1;
        // else
        //     hash[nums[i]]++;
        // }
        struct cmp_by_value
        {
            bool operator()(dict a, dict b)
            {
                return a.second > b.second; //min-heap
            }
        }; //TODO

        //max-heap by default
        // priority_queue<dict, vector<dict>, greater<dict>> min_heap;

        priority_queue<dict, vector<dict>, cmp_by_value> min_heap;
        vector<int> ans;
        for (auto &&i : counter)
        {
            if (min_heap.size() == k)
            {
                if (i.second < min_heap.top().second)
                    continue;
                min_heap.pop();
            }
            min_heap.push(i);
        }

        while (!min_heap.empty())
        {
            ans.push_back(min_heap.top().first);
            min_heap.pop();
        }

        return ans;
    }
};

// @lc code=end
