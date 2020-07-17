/*
 * @lc app=leetcode.cn id=973 lang=cpp
 *
 * [973] 最接近原点的 K 个点
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> points;
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        this->points = points;
        quick_select_sort(0, points.size() - 1, K);
        return vector<vector<int>>(this->points.begin(), this->points.begin() + K);
    }
    int dist(vector<int> coord)
    {
        return coord[0] * coord[0] + coord[1] * coord[1];
    }
    void quick_select_sort(int i, int j, int K)
    {
        if (i >= j)
            return;
        int oi = i, oj = j, pivot = dist(points[(i + j) >> 1]);
        for (;;)
        {
            while (dist(points[++i]) < pivot)
            {
            }
            while (dist(points[--j]) > pivot)
            {
            }
            cout << i << " " << j << endl;
            if (i < j)
                swap(points[i], points[j]);
            else
                break;
        }
        if (K <= (i - oi))
        {
            quick_select_sort(oi, i, K);
        }
        else
        {
            quick_select_sort(i + 1, oj, K - (i - oi + 1));
        }
    }
};
// @lc code=end
