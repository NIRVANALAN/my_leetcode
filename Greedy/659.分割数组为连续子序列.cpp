/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
// #include <unordered_map>
using namespace std;
class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, priority_queue<int, vector<int>, greater<int>>> chains; // big heap
        for (auto &&i : nums)
        {
            if (chains.find(i - 1) == chains.end() || chains[i - 1].empty())
            {
                chains[i].push(1); //initialize
            }
            else
            {
                int min_len = chains[i - 1].top();
                chains[i - 1].pop();
                chains[i].push(min_len + 1);
            }
        }
        for (auto i = chains.begin(); i != chains.end(); i++)
        {
            if (i->second.size() && i->second.top() < 3) // pq.size()==0 pq.top()!=null
                return false;
        }
        return true;
    }
    bool TLE(vector<int> &nums)
    {

        vector<vector<int>> sequences;
        int tmp_index, tmp_size;
        for (auto &&i : nums)
        {
            // sort(sequences.begin(), sequences.end(), [](vector<int> l, vector<int> r) {
            //     return l.size() < r.size();
            // }); //TLE
            tmp_index = -1, tmp_size = INT32_MAX;
            for (size_t j = 0; j < sequences.size(); j++)
            {
                if (sequences[j].back() == i - 1) // find the smallest sub_sequence
                {
                    if (sequences[j].size() < tmp_size)
                        tmp_index = j;
                }
            }
            if (tmp_index == -1)
                sequences.push_back(vector<int>{i});
            else
            {
                sequences[tmp_index].push_back(i); // push_back smallest
            }
        }
        for (auto &&i : sequences)
        {
            if (i.size() < 3)
                return false;
        }

        return true;
    }
};
// @lc code=end
