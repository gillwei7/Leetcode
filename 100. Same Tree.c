/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
        // 如果 p 和 q 都是 NULL, 表示一樣
        if(!p && !q)
            return true;
        // 如果 p 和 q 只有其中一個不是 NULL另外一個是, 表示不一樣
        // 如果 p 和 q 的 value 不同, 也表示不一樣
        if(!p || !q || (p->val != q->val))
            return false;
        // 這邊一定要同時 return 左子樹是不是一樣和 右子樹是不是一樣
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
