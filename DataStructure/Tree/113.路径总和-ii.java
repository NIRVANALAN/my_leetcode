/*
 * @lc app=leetcode.cn id=113 lang=java
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (58.03%)
 * Likes:    160
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 48K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
import java.util.List; //! attention
import java.util.ArrayList;

class Solution {
    // public class TreeNode {
    // int val;
    // TreeNode left;
    // TreeNode right;

    // TreeNode(int x) {
    // val = x;
    // }
    // }

    private List<List<Integer>> ret = new ArrayList<>();
    private List<Integer> tmpList = new ArrayList<>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        // dfs + prune
        dfs(root, sum);
        return ret;
    }

    public void dfs(TreeNode root, int sum) {
        if (root == null)
            return;
        // process
        sum -= root.val;
        tmpList.add(root.val);
        if (root.left == null && root.right == null && sum == 0) {
            ret.add(new ArrayList<>(tmpList));
        }

        dfs(root.left, sum);
        dfs(root.right, sum);

        tmpList.remove(tmpList.size() - 1); // * remove last element

    }
}
// @lc code=end
