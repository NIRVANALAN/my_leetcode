/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 *
 * https://leetcode-cn.com/problems/validate-binary-search-tree/description/
 *
 * algorithms
 * Medium (28.41%)
 * Likes:    407
 * Dislikes: 0
 * Total Accepted:    67.6K
 * Total Submissions: 234.1K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，判断其是否是一个有效的二叉搜索树。
 * 
 * 假设一个二叉搜索树具有如下特征：
 * 
 * 
 * 节点的左子树只包含小于当前节点的数。
 * 节点的右子树只包含大于当前节点的数。
 * 所有左子树和右子树自身必须也是二叉搜索树。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 1   4
 * / \
 * 3   6
 * 输出: false
 * 解释: 输入为: [5,1,4,null,null,3,6]。
 * 根节点的值为 5 ，但是其右子节点值为 4 。
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
#include <climits>
#include <stack>
using namespace std;
class Solution
{
public:
    long prev = LONG_LONG_MIN; // HHH
    // bool ret_val;
    bool isValidBST(TreeNode *root)
    {
        // return inorder_traversal_stack(root);
        return inorder_traversal_recursion(root);
    }
    bool inorder_traversal_stack(TreeNode *root)
    {
        stack<TreeNode *> nodes;
        while (root || nodes.size())
        {
            while (root)
            {
                nodes.push(root);
                root = root->left;
            }
            root = nodes.top();
            nodes.pop();
            if (root->val <= prev)
                return false;
            prev = root->val;
            root = root->right;
        }
        return true;
    }
    bool inorder_traversal_recursion(TreeNode *root) // TODO
    {
        if (!root)
            return true;
        if (inorder_traversal_recursion(root->left) && root->val > prev)
            prev = root->val;
        else
            return false;
        if (inorder_traversal_recursion(root->right))
            return true;
        return false;
        // else
        //     return false;
    }
};

/*

[-2147483648] // EMMMM
long prev = LONG_LONG_MIN; // HHH
*/
// @lc code=end
