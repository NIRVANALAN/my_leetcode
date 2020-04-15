/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */

// @lc code=start
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class StockSpanner
{
public:
    vector<int> prices;
    vector<int> ans; // ans[i]=the index of the first bigger value compared to i
    stack<int> s;    // monotonically decreasing
    StockSpanner()
    {
    }

    int next(int price)
    {
        prices.push_back(price);
        int rst = prices.size() - 1;
        while (!s.empty() && prices[s.top()] <= price)
        {
            rst = ans[s.top()];
            s.pop();
        }
        s.push(prices.size() - 1);
        ans.push_back(rst);
        return prices.size() - rst;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
