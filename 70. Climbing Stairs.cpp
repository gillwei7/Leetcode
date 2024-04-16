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
    int solve(int n, vector<int> &dp) {
        if(n <= 2)
            return n;
        if(dp[n] != -1)
            return dp[n];
        dp[n] = solve(n-1, dp) + solve(n-2, dp);
        return dp[n];
    }

    int climbStairs(int n) {
        if(n <= 2)
            return n;
        vector<int> dp(n+1, -1); // 這邊要存 n+1 個元素, 因為要涵蓋到n=0的範圍
        return solve(n,dp);
    }
};