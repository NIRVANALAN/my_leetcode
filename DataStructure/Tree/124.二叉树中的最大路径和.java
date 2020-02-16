/*
 * @lc app=leetcode.cn id=124 lang=java
 *
 * [124] 二叉树中的最大路径和
 *
 * https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/description/
 *
 * algorithms
 * Hard (38.75%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    23.2K
 * Total Submissions: 59.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个非空二叉树，返回其最大路径和。
 * 
 * 本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   3
 * 
 * 输出: 6
 * 
 * 
 * 示例 2:
 * 
 * 输入: [-10,9,20,null,null,15,7]
 * 
 * -10
 * / \
 * 9  20
 * /  \
 * 15   7
 * 
 * 输出: 42
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
// class TreeNode {
// int val;
// TreeNode left;
// TreeNode right;

// TreeNode(int x) {
// val = x;
// }
// }

class Solution {
    // public class TreeNode {
    // int val;
    // TreeNode left;
    // TreeNode right;

    // TreeNode(int x) {
    // val = x;
    // }
    // }

    private int pathsum = Integer.MIN_VALUE;
    private int left_sum, right_sum;

    public int maxPathSum(TreeNode root) {
        dfs(root);
        return pathsum;
    }

    public int dfs(TreeNode root) {
        if (root==null)
            return 0;
        int left_sum = Math.max(dfs(root.left), 0);
        int right_sum = Math.max(dfs(root.right), 0);
        pathsum = Math.max(pathsum, left_sum + right_sum + root.val);
        return root.val + Math.max(left_sum,right_sum);
    }

}
// @lc code=end
// [5,4,8,11,null,13,4,7,2,null,null,null,1]