/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (36.40%)
 * Likes:    3817
 * Dislikes: 0
 * Total Accepted:    309.6K
 * Total Submissions: 849.6K
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 * 
 * 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 * 
 * 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 示例：
 * 
 * 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 0 -> 8
 * 原因：342 + 465 = 807
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list. }
 */

class Solution {
    // public class ListNode {
    // int val;
    // ListNode next;

    // ListNode(int x) {
    // val = x;
    // }
    // }

    public int addTwoNodes(ListNode l1, ListNode l2, int residue) {
        residue = l1.val + l2.val + residue;
        l1.val = residue % 10;
        residue = residue / 10;
        return residue;
    }

    // ! use dummy head to initialize LinkedList
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode l1_start = l1;
        int residue = 0;
        while (true) {
            residue = addTwoNodes(l1, l2, residue);
            if (l1.next != null && l2.next != null) {
                l1 = l1.next;
                l2 = l2.next;
            } else
                break;
        }
        if (l1.next == null) {
            if (l2.next != null) {
                l1.next = l2.next;
            } else {

                if (residue != 0) {
                    l1.next = new ListNode(residue);
                }
                return l1_start;
            }
        }
        // else

        while (l1.next != null) {
            l1 = l1.next;
            residue = l1.val + residue;
            l1.val = residue % 10;
            residue /= 10;
        }
        if (residue != 0) {
            l1.next = new ListNode(residue);
        }
        return l1_start;
    }
}
// @lc code=end
