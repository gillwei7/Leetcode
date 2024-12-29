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
    bool isSymmetric(TreeNode* root) {
        // 二元樹慣例, 先檢查 root 有沒有存在
        if(!root) {
            return true;
        }
        // 因為要比較左邊節點和右邊節點是否一樣, 所以要定義另一個函數
        return dfs(root->left, root->right);
    }
    
    bool dfs(TreeNode* leftNode, TreeNode* rightNode) {
        // Base Case: 左節點和右節點都是 NULL
        if(!leftNode && !rightNode) {
            return true;
        }
        // 左節點和右節點只有其中一個不是 NULL, 或是兩個節點的值不一樣, 表示不對稱
        if(!leftNode || !rightNode || (leftNode->val != rightNode->val)) {
            return false;
        }
        // 左節點的左邊和右節點的右邊要一樣
        // 左節點的右邊和右節點的左邊要一樣
        return dfs(leftNode->left,rightNode->right) && dfs(leftNode->right,rightNode->left);
    }
};
