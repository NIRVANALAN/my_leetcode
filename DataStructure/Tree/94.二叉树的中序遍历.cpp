/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (69.67%)
 * Likes:    393
 * Dislikes: 0
 * Total Accepted:    102.7K
 * Total Submissions: 146.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
 * 
 * 示例:
 * 
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * 输出: [1,3,2]
 * 
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
#include <stack>
#include <vector>
using namespace std;
class Solution
{
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // };

public:
    vector<int> ret;
    stack<TreeNode *> inorder_stack;
    vector<int> inorderTraversal(TreeNode *root)
    {
        // 2. while
        // while()
        // traverse_recursion(root); //
        traverse_stack(root);
        return ret;
    }
    void traverse_recursion(TreeNode *root)
    {
        if (!root)
            return;
        // 1. recursion
        traverse_recursion(root->left);
        ret.push_back(root->val);
        traverse_recursion(root->right);
    }
    void traverse_stack(TreeNode *root)
    {
        while (!inorder_stack.empty() || root!=nullptr)
        {
            while (root != nullptr)
            {
                inorder_stack.push(root);
                root = root->left;
            }
            root = inorder_stack.top();
            inorder_stack.pop();
            ret.push_back(root->val);
            root = root->right;
        }
    }
    // int traversal
};
// @lc code=end
