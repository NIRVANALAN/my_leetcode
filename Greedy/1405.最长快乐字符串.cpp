/*
 * @lc app=leetcode.cn id=1405 lang=cpp
 *
 * [1405] 最长快乐字符串
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        typedef pair<int, char> IC;
        struct cmp
        {
            bool operator()(IC a, IC b)
            {
                return a.first < b.first;
            }
        } cmp;
        vector<IC> m{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string ans;
        int pre_size;
        while (true)
        {
            pre_size = ans.size();
            sort(m.rbegin(), m.rend(), cmp);
            // for (auto &&[cnt, c] : m)
            for (auto i = 0; i < m.size(); i++)
            {
                if (!m[i].first || ans.size() >= 2 && ans.back() == m[i].second && ans[ans.size() - 2] == m[i].second)
                    continue;
                m[i].first--;
                ans += m[i].second;
                break;
            }
            if (ans.size() == pre_size)
                break;
        }
        return ans;
    }
};
// @lc code=end
