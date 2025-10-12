class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // sliding window, 
        int l = 0; //左界, 右界會一直變動, 左界隨著 0 的數量變動
        int cnt = 0; // 0 的數量
        int ans = 0;
        // 右界擴張, 若遇到 0 就增加 cnt, 若 cnt 太高就要開始縮左界
        for(int r = 0;r < nums.size();r++){
            if(nums[r] == 0){
                cnt ++;
            }
            // 若 0 的數量太多, 左界往右縮
            while(cnt > k){
                if(nums[l] == 0){
                    cnt--;
                }
                l++;
            }
            ans = max( r-l+1, ans);
        }
        return ans;
    }
};