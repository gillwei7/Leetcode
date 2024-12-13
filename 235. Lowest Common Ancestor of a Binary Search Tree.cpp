/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       TreeNode * cur = root;
       // 只要 p, q 不在 Current node 的同一邊子樹 
       while(cur != nullptr) {
            // p, q 在 cur 的右子樹
            if(p->val > cur->val && q->val > cur->val) {
                cur = cur->right;
            }
            // p, q 在 cur 的左子樹
            else if(p->val < cur->val && q->val < cur->val) {
                cur = cur->left;
            }
            // p, q 不在 Current node 的同一邊子樹, 可以判定 cur 是 p, q 的 LCA
            else {
                return cur;
            }
       }
       return cur;
    }
};