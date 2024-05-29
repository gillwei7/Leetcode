class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 儲存最後結果的 array, pop 到第 k 個時就會是對的
        vector<vector<int>> result(k);
        //Maxheap 初始化, 由於題目只有需要第 k 個最靠近的距離, 所以 maxHeap 可以只維護 k 個就好, 後面沒有用到
        // 維護 minHeap的話複雜度較高, 因為每次 pop 出來之後還要更新 Heap
        //在 C++ 裡面用 priority_queue 且後面不用代參數進去, 就是 Maxheap
        //如果是 Minheap 就是 priority_queue <int, vector<int>, greater<int> > minHeap;
        priority_queue<vector<int>> maxHeap;
        //Construction of maxheap
        for (auto& p : points) {
            int x = p[0], y = p[1];
            maxHeap.push({x*x + y*y, x, y});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        
        for (int i = 0; i < k; ++i) {
            vector<int> top = maxHeap.top();
            maxHeap.pop();
            result[i] = {top[1], top[2]};
        }
        
        return result;
    }
};