/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // };

public:
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        // BFS(root);
        hierarchicalFS(root);
        return ans;
    }
    void BFS(TreeNode *root)
    {
        if (!root)
            return;                              //! nontrivial
        typedef pair<TreeNode *, int> nodeLevel; //* lint
        queue<nodeLevel> nodeQueue;
        nodeQueue.push(nodeLevel(root, 0));
        while (nodeQueue.size())
        {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            //? how to initialize vector<vector>
            if (ans.size() < node.second + 1)
                ans.push_back(vector<int>());
            ans[node.second].push_back(node.first->val);

            if (node.first->left) //! nontrivial
                nodeQueue.push(nodeLevel(node.first->left, node.second + 1));
            if (node.first->right)
                nodeQueue.push(nodeLevel(node.first->right, node.second + 1));
        }
    }

    void hierarchicalFS(TreeNode *root)
    {
        if (!root)
            return;
        queue<TreeNode *> nodeQue;
        nodeQue.push(root); // !
        while (nodeQue.size())
        {
            vector<int> tmp;
            size_t que_size = nodeQue.size(); //!
            for (size_t i = 0; i < que_size; i++)
            {
                auto node = nodeQue.front();
                tmp.push_back(node->val);

                if (node->left)
                    nodeQue.push(node->left);
                if (node->right)
                    nodeQue.push(node->right);
                nodeQue.pop();
            }
            ans.push_back(tmp);
        }
        // reverse(ans.begin(), ans.end());
    }
};
// @lc code=end
