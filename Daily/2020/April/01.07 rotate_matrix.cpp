#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int N = matrix.size();
        if (N == 0)
            return;
        int x = (N + 1) / 2;
        for (size_t i = x; i < N; i++)
        {
            for (int j = x - 1; j >= 0; j--)
            {
                swap(matrix[i][j], matrix[j][N - 1 - i]);
                swap(matrix[i][j], matrix[N - 1 - i][N - 1 - j]);
                swap(matrix[i][j], matrix[N - 1 - j][i]);
            }
        }
    }
};
/*
! math -> infer coordinates transformation*/