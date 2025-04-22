class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int r = 0,l = 0;
        int temp_num = 0;
        // 以 R 指標為基準, R 持續加1
	// 一開始遇到非零的數字, R 跟 L 會在同一個數字上交換, 所以 array 不變
        // 遇到零以後, R 才會往前, L 會停在零上面, 之後才會真正開始交換
        // 所以這邊不能用 L = 0, R = 1 開始, 這樣前面就有可能遇到 array 交換次序的情況發生
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
