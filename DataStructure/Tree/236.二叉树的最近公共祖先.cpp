/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
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
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    TreeNode *ans;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        dfs(root, p, q);
        return ans;
    }
    bool dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr || ans != nullptr) //! prune
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        if ((lson && rson) || ((lson || rson) && (root == p || root == q)))
            ans = root;
        return (lson || rson || root == p || root == q);
    }
    vector<TreeNode *> preOrderStackTraversal(TreeNode *root, TreeNode *target)
    {
        stack<TreeNode *> ss;
        vector<TreeNode *> ancestor;
        while (root != nullptr || !ss.empty())
        {
            while (root != nullptr)
            {
                if (root->val == target->val)
                {
                    return ancestor;
                }
                ancestor.push_back(root);
                ss.push(root);

                root = root->left;
            }
            root = ss.top()->right;
            ss.pop();
        }
        return ancestor;
    }
};
// @lc code=end
