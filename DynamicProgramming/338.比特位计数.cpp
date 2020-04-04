/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
#include <vector>
#include <iostream>
using std::vector;
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> rst;
        rst.push_back(0);
        auto i = 0;
        for (size_t i = 1; i <= num; i++)
        {
            rst.push_back(rst[i >> 1] + (i & 1));
        }

        // while (true)
        // {
        //     for (size_t j = 0; j < (1 << i); j++) //* i<<i == pow(2,i)
        //     {
        //         if (rst.size() == num + 1) //! num+1 && num=0
        //             return rst;
        //         rst.push_back(1 + rst[j]);
        //     }
        //     i++;
        // }
        return rst;
    }
};
// int main(int argc, char const *argv[])
// {
//     cout << (1 << 10);
//     cout << pow(2, 10);
// }

// @lc code=end
