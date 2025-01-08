class Solution {
public:
    // 題意: 計算 1 ~ n 每個數字的 binary 表示式 1 的數量, 回傳成 arrary
    // 一步一腳印法, 從 n 開始, 用 2 的餘數看目前的 bit 是否為 1, 然後一直進位, 直到變成 0
    // 所以每個 current 都需要一個 while loop, 也就是 log(n) 的計算時間
    // vector<int> countBits(int n) {
    //     if(n == 0) {
    //         return{0};
    //     }
    //     int current = n;
    //     vector<int> index(n+1,0);
    //     while(current > 0){
    //         printf("current:%d\n",current);
    //         int temp = current;
    //         while(temp > 0) {
    //             printf("temp:%d\n",temp);
    //             if(temp%2 == 1){
    //                 index[current]++;
    //             }
    //             temp = temp >> 1;
    //         }
    //         current--;
    //     }
    //     return index;
    // }

    // Dynamic programming
    vector<int> countBits(int n) {
        // 設定一個 offset 為 2^m, 只要到 2 的倍數就更新 offset
        // 每個值都可以用到 offset 之前的值為參考
        vector<int> dp(n+1, 0);
        int offset = 1;
        for(int i = 1;i <= n; i++) {
            if(offset * 2 == i){
                offset = i;
            }
            dp[i] = 1 + dp[i - offset];
        }
        return dp;
    }
};
