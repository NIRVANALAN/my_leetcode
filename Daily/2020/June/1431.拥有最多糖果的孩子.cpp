/*
 * @lc app=leetcode.cn id=1431 lang=cpp
 *
 * [1431] 拥有最多糖果的孩子
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> ret(candies.size());
        if (!ret.size())
            return ret;
        int max_candy = *max_element(candies.begin(), candies.end());
        for (size_t i = 0; i < candies.size(); i++)
        {
            ret[i] = ((candies[i] + extraCandies) >= max_candy);
        }
        return ret;
    }
};
// @lc code=end
