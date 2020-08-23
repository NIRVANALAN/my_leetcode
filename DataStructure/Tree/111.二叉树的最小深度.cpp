/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode *root) //* DFS
    {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        int min_depth = INT_MAX;
        if (root->left)
            min_depth = min(minDepth(root->left), min_depth);
        if (root->right)
            min_depth = min(minDepth(root->right), min_depth);
        return min_depth + 1;
        // int left = 0, right = left;
        // if (root->left)
        //     left = minDepth(root->left);
        // if (root->right)
        //     right = minDepth(root->right);
        // if (right && left)
        //     return min(left, right) + 1;
        // return left > 0 ? left + 1 : right + 1;
    }
};
// @lc code=end
