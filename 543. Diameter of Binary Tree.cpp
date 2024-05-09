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
    int result_diameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        dfs_height(root);
        return result_diameter;
    }
    int dfs_height(TreeNode* root){
        if(root == nullptr) {
            return -1;
        }
        int height_left = dfs_height(root->left);
        int height_right = dfs_height(root->right);
        result_diameter = max(result_diameter, 2 + height_left + height_right);
        return 1 + max(height_left,height_right);
    }
};