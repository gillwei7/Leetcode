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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
	//如果 root 和 subRoot 同時為空, 即為相同, 符合比較條件
        if(!root && !subRoot) {
            return true;
        }
	// 如果 root 和 subRoot 只有一個為空, 另一個不為空, 則不同, 不符合條件
        if(!root || !subRoot) {
            return false;
        }
	// 如果 root 和 subRoot 為一樣的樹, 即符合條件 
        if(isSameTree(root, subRoot)){
            return true;
        }
	// 沒有符合條件, 可以再繼續比下去直到 root 為空沒辦法繼續比
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
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

};
