/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 *
 * https://leetcode-cn.com/problems/task-scheduler/description/
 *
 * algorithms
 * Medium (47.02%)
 * Likes:    174
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 26.2K
 * Testcase Example:  '["A","A","A","B","B","B"]\n2'
 *
 * 给定一个用字符数组表示的 CPU 需要执行的任务列表。其中包含使用大写的 A - Z 字母表示的26
 * 种不同种类的任务。任务可以以任意顺序执行，并且每个任务都可以在 1 个单位时间内执行完。CPU
 * 在任何一个单位时间内都可以执行一个任务，或者在待命状态。
 * 
 * 然而，两个相同种类的任务之间必须有长度为 n 的冷却时间，因此至少有连续 n 个单位时间内 CPU 在执行不同的任务，或者在待命状态。
 * 
 * 你需要计算完成所有任务所需要的最短时间。
 * 
 * 示例 1：
 * 
 * 
 * 输入: tasks = ["A","A","A","B","B","B"], n = 2
 * 输出: 8
 * 执行顺序: A -> B -> (待命) -> A -> B -> (待命) -> A -> B.
 * 
 * 
 * 注：
 * 
 * 
 * 任务的总个数为 [1, 10000]。
 * n 的取值范围为 [0, 100]。
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        auto map = vector<int>(26);
        for (auto &i : tasks)
            map[i - 'A']++;

        priority_queue<int> max_heap;
        for (auto &i : map)
            if (i > 0)
                max_heap.push(i);
        int time = 0, i = 0;
        vector<int> temp;

        while (!max_heap.empty())
        {
            i = 0;
            temp.clear();
            while (i <= n) // max n+1 tasks
            {
                if (!max_heap.empty())
                {
                    if (max_heap.top() > 1)
                        temp.push_back(max_heap.top() - 1);
                    max_heap.pop();
                }
                time++;
                if (temp.empty() && max_heap.empty())
                    break;
                i++;
            }
            for (auto &i : temp)
                max_heap.push(i);
        }
        return time;
    }
};

// int main(int argc, char const *argv[])
// {
//     auto s = Solution();
//     auto tasks = vector<char>{'A'};
//     auto ret = s.leastInterval(tasks, 2);
//     std::cout << ret;
//     return 0;
// }

// @lc code=end
