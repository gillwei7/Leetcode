// 20250325 不知道怎麼直接在 function 中進行遞迴  
// add git log

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
    TreeNode* invertTree(TreeNode* root) {
        // 這邊處理的除了原本 root 是空的, 還有就是最後的葉子樹 case null 的話
        // 一定要return
        if(root==nullptr)
            return nullptr;
        // Swap function 要寫在裡面, 如果寫在外面另一個 function , 然後再帶入的話
        // 就只有 swap 到最左邊和最右邊的一排
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;
        // 處理完左邊和右邊的子樹就可以 return 了
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

};
