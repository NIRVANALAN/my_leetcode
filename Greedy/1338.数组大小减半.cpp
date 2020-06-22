/*
 * @lc app=leetcode.cn id=1338 lang=cpp
 *
 * [1338] 数组大小减半
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minSetSize(vector<int> &arr)
    {
        unordered_map<int, int> unorder;
        for (auto &&i : arr)
        {
            unorder[i]++;
        }
        priority_queue<int> ordered_freq; //! decending
        for (auto &&[k, v] : unorder)
        {
            ordered_freq.push(v);
        }
        int count = 0, ans = 0;
        while (ordered_freq.size())
        {
            count += ordered_freq.top();
            ordered_freq.pop();
            ans++;
            if (count >= arr.size() / 2)
                break;
        }
        return ans;
    }
};
// @lc code=end
