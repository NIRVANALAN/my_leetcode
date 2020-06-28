/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
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
class Solution
{
public:
    int max_depth = 0, tmp = 0;
    int maxDepth(TreeNode *root)
    {
        // preOrderTraversal(root);
        // return max_depth;
        return root == nullptr ? 0 : max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    void preOrderTraversal(TreeNode *node)
    {
        if (node == nullptr)
            return;
        tmp++;
        if (tmp > max_depth)
            max_depth = tmp;
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
        tmp--;
    }
};
// @lc code=end
