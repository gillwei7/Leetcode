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
#else
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
#endif


};