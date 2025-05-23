class Solution {
public:
    // 遞迴函數, 會觸發 Time exceed limit
    // int fi(int n) {
    //     if(n <= 1) {
    //         return 1;
    //     }
    //         return (fi(n - 1) + fi(n - 2));
        
    // }
    // int climbStairs(int n) {
    //     return fi(n);
    // }

    // Dynamic programming
    // 直接使用從 f(0),f(1),f(2) 開始記錄起來
    // 然後後面就可以直接使用前面兩個數字相加即可
    // 要注意因為 vector 的 index 會從 0 開始存, 所以如果 init 的時候用 vector<int> dp(n)
    // 會發現最後存取到沒有初始化的 dp[n], 所以記得要初始化 vector<int> dp(n+1)
    // 但是這個方法還是會用到 memory n
    
    // int climbStairs(int n) {
    //     if(n == 1){
    //         return 1;
    //     } else if (n == 2){
    //         return 2;
    //     }

    //     vector<int> dp(n+1);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     dp[2] = 2;
    //     for(int i = 3;i <= n;i++){
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    // 所以我們只要把要用到的前兩個存起來就好了
    // 有新的就把舊的換掉, 不過還需要第三個變數當作 temp value
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }

        int prev1 = 2; // Ways to climb 2 steps
        int prev2 = 1; // Ways to climb 1 step
        int current;
        for (int i = 3; i <= n; i++) {
            current = prev1 + prev2; // Ways to climb i steps
            prev2 = prev1;           // Update prev2 to prev1
            prev1 = current;         // Update prev1 to current
        }
        return current;
    }
};