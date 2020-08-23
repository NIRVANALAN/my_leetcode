/*
 * @lc app=leetcode.cn id=201 lang=cpp
 *
 * [201] 数字范围按位与
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        return shiftRange(m, n);
        // if (n == 0)
        //     return 0;
        // if (m == n)
        //     return n;
        // cout << m << " " << n << endl;
        // int upperBound = floor(log2(n)), a, b;
        // long res = 0;
        // long power;
        // for (long i = 0; i <= upperBound; i++)
        // {
        //     power = pow(2, i);
        //     a = m / power;
        //     b = n / power;
        //     if (a == b && a % 2 == 1)
        //     {
        //         res += power;
        //         cout << power << endl;
        //     }
        // }

        // return res;
    }
    int shiftRange(int m, int n)
    {
        int shift = 0;
        while (m < n)
        {
            m >>= 1;
            n >>= 1;
            shift++;
        }
        return m << shift;
    }
};
// @lc code=end

// 因此，最终我们可以将问题重新表述为：给定两个整数，我们要找到它们对应的二进制字符串的公共前缀。
int main(int argc, char const *argv[])
{
    auto s = Solution();
    cout << s.rangeBitwiseAnd(5, 7) << endl;
    return 0;
}
