/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if(root == NULL) {
        return 0;
    }
    int leftLength = maxDepth(root->left);
    int rightLength = maxDepth(root->right);
    return 1 + (leftLength > rightLength ? leftLength : rightLength);
}