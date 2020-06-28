#include <bits/stdc++.h>
using namespace std;

class TreeTraversal
{
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    void preOrderRecursiveTraversal(TreeNode *node)
    {
        if (node == nullptr)
            return;
        cout << node->val << endl;
        preOrderRecursiveTraversal(node->left);
        preOrderRecursiveTraversal(node->right);
    }
    void preOrderIterationTraversal(TreeNode *root)
    {
        if (root == nullptr)
            return;
        stack<TreeNode *> callStack;
        while (!callStack.empty() || root != nullptr)
        {
            callStack.push(root);
            cout << root->val << endl;
            while (root != nullptr)
            {
                root = root->left;
                callStack.push(root);
            }
            root = callStack.top()->right;
            callStack.pop(); //! Nontrivial. This operation is different from language function call stack
        }
    }
    void BFS(TreeNode *root)
    {
        queue<TreeNode *> nodeQueue;
        nodeQueue.push(root);
        while (nodeQueue.size() || root != nullptr)
        {
            auto node = nodeQueue.front();
            nodeQueue.pop();
            cout << node->val << " "; //

            nodeQueue.push(node->left);
            nodeQueue.push(node->right);
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
            size_t que_size = nodeQue.size(); //!
            for (size_t i = 0; i < que_size; i++)
            {
                auto node = nodeQue.front();
                //* manipulation

                if (node->left)
                    nodeQue.push(node->left);
                if (node->right)
                    nodeQue.push(node->right);
                nodeQue.pop();
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
