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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    // 使用遞迴方式, 所以增加一個 helper function, 傳入 vector 和左右節點數字
private:
    TreeNode* helper(const vector<int>& nums, int left, int right) {
        // 最基本的情況是只要左數字大於右數字就回傳空值
        if(left > right) {
            return nullptr;
        }
        // 算出中間值, 但是預防會有 overflow, 所以先用右數字減左數字 / 2, 再加上左數字
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->right = helper(nums, mid + 1, right); // 右子樹由 mid + 1 當作最左邊
        root->left = helper(nums, left, mid - 1); // 左子樹由 mid - 1 當作最右邊
        return root;
    }
};