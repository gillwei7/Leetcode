class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0];
        int curSum = 0;
        for(int i = 0; i < nums.size();i++) {
            // 如果 current sum 小於零, 就可以直接捨棄掉
            if(curSum < 0){
                curSum = 0;
            }
            curSum += nums[i];
            maxSub = max(maxSub, curSum);
        }
        return maxSub;
    }
};
