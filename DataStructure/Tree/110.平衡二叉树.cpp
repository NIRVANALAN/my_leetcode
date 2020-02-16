/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (49.56%)
 * Likes:    220
 * Dislikes: 0
 * Total Accepted:    48K
 * Total Submissions: 96.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 * 
 * 本题中，一棵高度平衡二叉树定义为：
 * 
 * 
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 * 
 * 
 * 示例 1:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7]
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回 true 。
 * 
 * 示例 2:
 * 
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 * 
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 * 
 * 
 * 返回 false 。
 * 
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <math.h>
#include <algorithm>
class Solution
{
public:
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // };

    bool isBalanced(TreeNode *root)
    {
        return dfs(root) != -1;
    }
    int dfs(TreeNode *root)
    {
        if (!root)
            return 0;
        int left_depth = dfs(root->left);
        if (left_depth == -1)
            return -1;
        int right_depth = dfs(root->right);
        if (right_depth == -1)
            return -1;
        if (abs(right_depth - left_depth) > 1)
            return -1;
        else
            return std::max(left_depth, right_depth) + 1;
    }
};

// @lc code=end

/*
227/227 cases passed (12 ms)
Your runtime beats 91.92 % of cpp submissions
Your memory usage beats 9.08 % of cpp submissions (17.7 MB)
*/