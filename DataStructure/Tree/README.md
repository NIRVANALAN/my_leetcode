# Tree

- DFS
- Inorder traversal 
- Morris 114(Feb 16th)
- BFS(层次遍历) 297
   - TODO 103


## typedef
```
typedef struct {int a; int b;} S, *pS;
typedef unsigned long ulong;
```

## stringstream
```
    #include <sstream>
    using namespace std;
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

```

## Experiences
- Stack version is usually better than recursion, especially when pruning is adopted(98). Recursion version needs more ```return``` compared to stack. 
- ```auto``` declaration will not bring much cost
- 


