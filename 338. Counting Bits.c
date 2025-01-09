/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize) {
    // returnSize 記得要填上, 因為是 0 ~ n 所以有 n+1 個
    *returnSize = n + 1;
    int offset = 1;
    int* dp = (int*)malloc((n+1) * sizeof(int));

    // 這裡是給實際在板子上用, malloc 有可能真的會失敗
    if(dp == NULL) {
        *returnSize = 0;
        return NULL;
    }

    // 後面的值都會一直用到前面的, 記得 dp[0] 一定要設定好
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        if(i == 2 * offset){
            offset = i;
        }
        dp[i] = 1 + dp[i - offset];
        //printf("dp[%d]:%d\n", i, dp[i]);
    }
    return dp;
}

