/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 *
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (43.53%)
 * Likes:    131
 * Dislikes: 0
 * Total Accepted:    14.2K
 * Total Submissions: 31.9K
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * 
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 /
 * 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 
 * 示例: 
 * 
 * 你可以将以下二叉树：
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   3
 * ⁠    / \
 * ⁠   4   5
 * 
 * 序列化为 "[1,2,3,null,null,4,5]"
 * 
 * 提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode
 * 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
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
// #include <algorithm>
#include <queue>
#include <string>
#include <sstream>
using namespace std;
class Codec
{
public:
    // struct TreeNode
    // {
    //     int val;
    //     TreeNode *left;
    //     TreeNode *right;
    //     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    // };

    // encodes a tree to a single string.
    string serialize(treenode *root)
    {
        if (!root)
            return "";
        queue<treenode *> nodeque;
        stringstream ss;
        nodeque.push(root);
        while (nodeque.size())
        {
            root = nodeque.front();
            nodeque.pop();
            if (!root)
                ss << "# ";
            else
            {
                ss << root->val << " ";
                nodeque.push(root->left);
                nodeque.push(root->right);
            }
        }
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.empty())
            return nullptr;
        stringstream ss(data);
        queue<TreeNode *> nodeque;
        string st;
        ss >> st;
        auto node = new TreeNode(stoi(st));
        auto rst = node;
        nodeque.push(node);
        while (nodeque.size())
        {
            node = nodeque.front();
            nodeque.pop();
            ss >> st;
            if (st[0] == '#')
            {
                node->left == nullptr;
            }
            else
            {
                node->left = new TreeNode(stoi(st));
                nodeque.push(node->left);
            }
            ss >> st;
            if (st[0] == '#')
            {
                node->right == nullptr;
            }
            else
            {
                node->right = new TreeNode(stoi(st));
                nodeque.push(node->right);
            }
        }
        return rst;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
// @lc code=end
