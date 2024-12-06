class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0,l = 0;
        int temp_num = 0;
        // 以 R 指標為基準, R 持續加1
        while(r < nums.size()) {
            if(nums[r] != 0) {
                // 只要 R 指標不為 0, 交換 R 指標和 L 指標
                temp_num = nums[r];
                nums[r] = nums[l];
                nums[l] = temp_num;
                // 記得這時候 L 指標也要加1
                l ++;
            }
            r++;
        }
    }
};