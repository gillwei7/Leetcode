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
// 因為這個方式是先處理目前的 Node, 再依序處理左子節點和右子節點
// 我們要先創立一個 stack 裡面儲存現在的 Node 和 深度, 如果現在的深度比較深就更新結果
// 有給出 Node 和 深度就 pop 掉, 然後再加入左子節點和右子節點(如果有的話)
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int resultDepth = 1;
        stack<pair<TreeNode*, int>> nodeStack;
        TreeNode* currentNode; // 目前正在處理的 Node
        int currentDepth; // 目前處理的 Node 的 length
        nodeStack.push({root, 1}); // 先把 root 加進去

        while(!nodeStack.empty()) {
            // 這邊記得 stack 用法是先用 top() 取出來, 取完後再 pop() 掉
            pair<TreeNode*, int> currentPair = nodeStack.top();
            currentNode = currentPair.first;
            currentDepth = currentPair.second;
            nodeStack.pop();
            // 先處理現在的節點, 深度有比較深的話就更新
            if(currentDepth > resultDepth) {
                resultDepth = currentDepth;
            }
            // 加入左右子節點, 記得深度都要加 1
            if(currentNode->left)  nodeStack.push({currentNode->left,currentDepth + 1});
            if(currentNode->right)  nodeStack.push({currentNode->right,currentDepth + 1});
        }
        return resultDepth;
    }

#endif


};
