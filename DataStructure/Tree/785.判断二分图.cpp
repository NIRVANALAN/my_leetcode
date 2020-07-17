/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &graph)
    {
        // bfs
        int flag[graph.size()];
        for (size_t i = 0; i < graph.size(); i++)
        {
            flag[i] = -1;
        }

        queue<int> q;
        for (size_t node = 0; node < graph.size(); node++)
        { //! make sure every node is iterated
            if(flag[node]==-1)
            {
        q.push(node);
        while (q.size())
        {
            int root = q.front();
            q.pop();
            if (flag[root] == -1)
                flag[root] = 0;
            int son;
            for (size_t i = 0; i < graph[root].size(); i++)
            {
                son = graph[root][i];
                if (flag[son] != -1)
                {
                    if (flag[son] == flag[root])
                        return false;
                    else
                        continue;
                }
                flag[son] = 1 - flag[root];
                q.push(son);
            }
        }
            }
        else
            continue;
        }


        return true;
    }
};
// @lc code=end
