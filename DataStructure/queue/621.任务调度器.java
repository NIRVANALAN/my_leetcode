
// import java.util.Collection;
// import java.time.temporal.TemporalField;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

/*
 * @lc app=leetcode.cn id=621 lang=java
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
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char i : tasks) {
            map[i - 'A']++;
        }
        PriorityQueue<Integer> max_heap = new PriorityQueue<>(26, Collections.reverseOrder()); // ?
        for (int task : map) {
            if (task > 0) {
                max_heap.add(task);
            }
        }
        int time = 0, i = 0;
        ArrayList<Integer> temp = new ArrayList<>();
        while (!max_heap.isEmpty()) {
            i = 0;
            temp.clear();
            while (i <= n) {
                if (!max_heap.isEmpty()) {
                    if (max_heap.peek() > 1) {
                        temp.add(max_heap.poll() - 1);
                    } else
                        max_heap.poll();
                }
                time++;
                if (max_heap.isEmpty() && temp.isEmpty()) {
                    break;
                }
                i++;
            }
            for (int task : temp) {
                max_heap.add(task);
            }
        }

        return time;
    }

    // public static void main(String[] args) {
    // System.out.println("first java in vscode");
    // }
}
// @lc code=end
