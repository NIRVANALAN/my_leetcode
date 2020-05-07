
// @lc code=start
#include <vector>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
using std::min;
using std::vector;
//* @lc app=leetcode.cn id=1277 lang=cpp
/*
1. from above to bottm
2. right_bottom corner, rather than left_up 
*/
class Solution
{
public:
    int countSquares(vector<vector<int>> &matrix)
    {
        // return upper_left(matrix);
        return lower_right(matrix);
    }
    int lower_right(vector<vector<int>> &matrix)
    {
        int rst = 0;
        for (size_t i = 0; i < matrix.size(); i++)
        {
            for (size_t j = 0; j < matrix[0].size(); j++)
            {
                if (i != 0 && j != 0 && matrix[i][j])
                {
                    matrix[i][j] = min(min(matrix[i - 1][j], matrix[i - 1][j - 1]), matrix[i][j - 1]) + 1;
                }
                rst += matrix[i][j];
            }
        }
        return rst;
    }
    int upper_left(vector<vector<int>> &matrix)
    {
        //* init
        int rst = 0;
        int m = matrix.size(), n = matrix[0].size();
        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++)
                rst += matrix[i][j]; //*1
        //* 2
        for (size_t side = 2; side <= min(m, n); side++)
        {
            for (size_t i = 0; i < m - 1; i++)
            {
                for (size_t j = 0; j < n - 1; j++)
                {
                    if (square(i, j, side - 1, matrix))
                    {
                        matrix[i][j] = side;
                        rst++;
                    }
                }
            }
        }
        return rst;
    }
    bool square(int i, int j, int side, vector<vector<int>> &matrix)
    {
        for (size_t a = i; a <= i + 1; a++)
            for (size_t b = j; b <= j + 1; b++)
                if (matrix[a][b] != side)
                    return false;
        return true;
    }
};
// @lc code=end
