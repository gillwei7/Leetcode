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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }
        // 用 BFS, 要先創一個 Node 的 queue 出來, 把同一層的節點都加進去
        // 一開始先加 root
        // 後面就是加上目前 Node 的 left 和 right
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            cout << "q.size" << s << endl;
            // v 即為同一層的 node value
            vector<int> v; 
            // 對於同一層的 Node 取出後, 把 left 跟 right push 回去 queue
            for(int i = 0;i < s;i++) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left != nullptr) q.push(node->left);
                if(node->right != nullptr) q.push(node->right);
                v.push_back(node->val);
            }
            // 把同一層的加到結果
            ans.push_back(v);
        }
        return ans;
    }
};