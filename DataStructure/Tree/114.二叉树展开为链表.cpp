/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (66.80%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    26.1K
 * Total Submissions: 38.6K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
#include <vector>
using namespace std;
class Solution
{
public:
    vector<TreeNode *> nodes;
    // TreeNode *prev;
    void flatten(TreeNode *root)
    {
        /*inorder traversal + modify pointer*/
        // dfs(root);
        // if(!nodes.size())
        //     return;
        // nodes[nodes.size() - 1]->left = nullptr;
        // for (auto i = 0; i < nodes.size() - 1; i++)
        // {
        //     nodes[i]->left = nullptr;
        //     nodes[i]->right = nodes[i + 1];
        // }
        /*morris*/
        if(!root)
            return;
        morris(root);
    }
    void morris(TreeNode *root)
    {
        // if (!root)
        //     return;
        // while (root != nullptr)
        // {
        if (root->left != nullptr)
        {
            auto prev = root->left;
            while (prev->right)
                prev = prev->right;
            prev->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        // root = root->right;
        // }
        if(root->right)
            morris(root->right);
    }
    void dfs(TreeNode *root)
    {
        if (!root)
            return;
        nodes.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
};
// @lc code=end
