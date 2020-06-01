/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{

    static bool sort_vector_of_vector(const vector<int> a, const vector<int> b)
    {
        return a[1] < b[1];
    }
    //*lambda expression: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (!intervals.size())
            return 0;
        // sort(intervals.begin(), intervals.end(), sort_vector_of_vector);
        sort(intervals.begin(), intervals.end(), [](const vector<int> &l, const vector<int> &r) { //! quicker & efficient, why?
            return l[1] < r[1];
        });
        int length = 1, f = intervals[0][1];
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] >= f)
            {
                f = intervals[i][1];
                length++;
            }
        }
        return intervals.size() - length;
    }
};
// @lc code=end
