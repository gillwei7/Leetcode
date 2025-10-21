class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> vis; // 這邊用 unordered_set 只有一個數字
        int result = 0; // 計算共幾次操作
        for(int i = nums.size()-1;i >= 0;i--){
            result++;
            // 要檢查目前的數字小於等於 k 才加入 
            if(nums[i] <= k){
                vis.insert(nums[i]);
            }
            if(vis.size() == k){
                return result;
            }
        }
        return 0;
    }
};