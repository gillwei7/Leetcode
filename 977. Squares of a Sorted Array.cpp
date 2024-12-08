class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();  // 會用到很多次, 先存起來
        vector<int> result(n); // 因為是從 vector 最後面開始填值, 先指定好長度才比較好從後面往前填
        int l = 0,r = n-1; // 左右指標
        int index = n - 1; // 填值 index 從最後面開始
        while(l <= r) { // 這裡記得要有等於, 不然最中間那個數字會沒填到 result 裡面
            int rSquare = nums[r] * nums[r];
            int lSquare = nums[l] * nums[l];
            // 從最左和最右邊開始比較, 平方值比較大的填入 result
            if(rSquare > lSquare) {
                result[index] = rSquare;
                r--;
            }
            else {
                result[index] = lSquare;
                l++;
            }
            index--; // 這裡記得要 index --
        }
        return result;

    }
};