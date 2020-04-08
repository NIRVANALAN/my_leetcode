/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
// using std::min;
// using std::string;
using namespace std;
// @lc code=start
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int memory[word1.size() + 1][word2.size() + 1];
        //* init
        for (size_t i = 0; i <= word1.size(); i++)
            memory[i][0] = i;
        for (size_t i = 1; i <= word2.size(); i++)
            memory[0][i] = i;
        //* dp
        for (size_t i = 1; i <= word1.size(); i++)
        {
            for (size_t j = 1; j <= word2.size(); j++)
            {
                memory[i][j] = min(min(memory[i - 1][j], memory[i][j - 1]) + 1, memory[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }

        return memory[word1.size()][word2.size()];
    }
};
// @lc code=end
