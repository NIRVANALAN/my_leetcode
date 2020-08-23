/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int _x[4] = {0, 1, 0, -1};
    int _y[4] = {1, 0, -1, 0};
    void solve(vector<vector<char>> &board)
    {
        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[0].size() - 1) && board[i][j] == 'O')
                    dfs(i, j, board);
            }
        for (size_t i = 0; i < board.size(); i++)
            for (size_t j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '-')
                    board[i][j] = 'O';
            }
    }
    void dfs(int i, int j, vector<vector<char>> &board)
    {
        if (i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1 || board[i][j] != 'O')
            return;
        board[i][j] = '-';
        for (int k = 0; k < 4; k++)
            dfs(i + _x[k], j + _y[k], board);
    }
};
// @lc code=end
