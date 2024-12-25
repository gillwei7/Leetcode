/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
#if 0
    // Recursive DFS method 
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0; // Base case: the depth of an empty tree is 0
        }
        
        // Recursively find the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The maximum depth is 1 (current node) plus the maximum of the two subtrees
        return 1 + std::max(leftDepth, rightDepth);
    }

    // BFS method
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int depth = 0;
        while(!nodeQueue.empty()) {
            int levelSize = nodeQueue.size(); // Number of nodes at the current level
            for(int i = 0;i < levelSize; i++) {
                TreeNode* currentNode = nodeQueue.front();
                nodeQueue.pop();
                if(currentNode->left) nodeQueue.push(currentNode->left);
                if(currentNode->right) nodeQueue.push(currentNode->right);
            }
            depth ++;
        }
        return depth;
    }
#else
// Iterative DFS, Use Stack, pre-Order traversal
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        stack<pair<TreeNode*, int>> currentStack;
        currentStack.push({root,1});
        int resultDepth = 1;

        while(!currentStack.empty()) {
            // 這邊要用 auto 比較方便, 不然用 pair 的話就要用 .first .second 有點煩人
            auto[currentNode,nodeDepth] = currentStack.top();
            currentStack.pop();
            resultDepth = max(resultDepth,nodeDepth);
            if(currentNode->left) currentStack.push({currentNode->left,nodeDepth+1});
            if(currentNode->right) currentStack.push({currentNode->right,nodeDepth+1});
        }
        return resultDepth;

    }

#endif


};
