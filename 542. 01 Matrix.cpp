class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        // 做一個 distance matrix, 所有值初始化為 INT_MAX
        // 從每個 0 開始, 往外擴散, 如果有遇到 1 的話檢查, 如果 distance 可以變小的話就做更新
        // Q: 不能從每個 1 往外擴散嗎?
	// A: 從 1 開始往外擴散也可以, 但是 leetcode 裡面的 case 1 比較多, 所以會跑很久
        // 若遇到 element 0, distance 即標註為 0, 遇到 1 不變
        // 為了要做 BFS 要有一個 queue 標註所有 0 的位置, 每次先把 queue 所有鄰居都檢查完是否需要更新後, 再去檢查下一個
        // 要有一個 direction 上下左右表示往哪邊走, 來讓 distance matrix 相加或相減
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        for(int i = 0;i < m; i++) {
            for(int j = 0;j < n;j++) {
                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        // direction 設定為 {上,下,左,右}
        vector<pair<int,int>> direction = {{-1, 0},{1, 0},{0, -1},{0, 1}};
        // 使用 BFS 更新 distance matrix
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for(auto [dr,dc]: direction) {
                int nr = r + dr;
                int nc = c + dc;
                // 檢查加上 direction 後的位置是否合法, 合法後是否需要更新 distance matrix
                if(nr >= 0 && nr < m && nc >=0 && nc < n && (dist[r][c] + 1 < dist[nr][nc])) {
                    dist[nr][nc] = dist[r][c] + 1;
                    // 更新完之後, 再加入 pair 裡面, 等待重新檢查
                    q.push({nr,nc});
                }

            }
        }
        return dist;
    }
};