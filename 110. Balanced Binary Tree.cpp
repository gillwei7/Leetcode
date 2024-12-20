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
    bool isBalanced(TreeNode* root) {
        // 第一我們需要下一層是否為 balanced, 不是的話就可以直接 return false, 
        // 第二我們需要下一層的高度, 選左邊或右邊比較高的再 +1 來當作高度
        // 因為這個 function 只有回傳 boolean, 但是沒有高度的話上一層沒辦法判斷是否平衡樹, 所以必須用另一個 function 來做遞迴
        return dfs_height(root).second;
    }
    // 這邊要回傳兩個值, 用 pair, return { , }, 要使用值的時候用 .first 或 .second
    // 如果是 tuple , 一樣 return { , }, 使用值的時候用 get<1>(dfsHeight(root))
    pair<int , bool> dfs_height(TreeNode* root) {
        // 首先如果是 Null 還是要先處理
        if(root == nullptr) {
            return {0, true};
        }
        // 這邊要算出左子樹的 balanced 和 height, 先各自用 pair 存比較乾淨
        pair<int, bool> left = dfs_height(root->left);
        pair<int, bool> right = dfs_height(root->right);
        // 計算高度, 要記得算出最高的以後要加 1
        int resultHeight = 1 + max(left.first, right.first);
        // Balanced 的條件, 除了左子樹和右子樹本身都要是平衡, 兩邊高度差必須小於 1
        bool isBalanced = left.second && right.second && (abs(left.first - right.first) <= 1);
        return {resultHeight, isBalanced};
        
    }
};
