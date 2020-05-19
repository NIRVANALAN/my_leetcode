/*
 * @lc app=leetcode.cn id=1262 lang=cpp
 *
 * [1262] 可被三整除的最大和
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int trash(vector<int> &nums)
    {

        int a0, a1, a2, tmp;
        a0 = a1 = a2 = tmp = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 3 == 0)
            {

                a0 += nums[i];
                if (a1)
                    a1 += nums[i];
                if (a2)
                    a2 += nums[i];
            }
            else if (nums[i] % 3 == 1)
            {
                tmp = a0;
                if (a2) //update rst
                    a0 = max(a2 + nums[i], a0);
                if (a1) //update a2
                    a2 = max(a2, a1 + nums[i]);
                a1 = max(a1, tmp + nums[i]);
            }
            else
            {
                tmp = a0;
                if (a1)
                    a0 = max(a1 + nums[i], a0);
                if (a2)
                    a1 = max(a1, a2 + nums[i]);
                a2 = max(a2, tmp + nums[i]);
            }
            cout << a0 << " " << a1 << " " << a2 << endl;
        }
        return a0;
    }
    int maxSumDivThree(vector<int> &nums)
    {
        int dp[3] = {0, 0, 0};
        for (size_t i = 0; i < nums.size(); i++)
        {
            int mod = nums[i] % 3;
            // previous state
            int a = dp[(3 + 0 - mod) % 3];
            int b = dp[(3 + 1 - mod) % 3];
            int c = dp[(3 + 2 - mod) % 3];

            //dp
            if (a || mod == 0)
                dp[0] = max(dp[0], a + nums[i]);
            if (b || mod == 1)
                dp[1] = max(dp[1], b + nums[i]);
            if (c || mod == 2)
                dp[2] = max(dp[2], c + nums[i]);
        }
        return dp[0];
    }
};
// @lc code=end
//* 变量更新的先后顺序