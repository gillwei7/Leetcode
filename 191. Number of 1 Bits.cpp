class Solution {
public:
    int hammingWeight(int n) {
#if 0
        // 照慣例先處理為 0 的情況
        if(n == 0)
            return 0;

        // 如果 current 對 2 的餘數為 1, 表示目前最小的數字為 1
        // 然後依序往左邊計算, 每次有算到就把結果 +1
        int current = n;
        int result = 0;
        while(current > 0){
            if(current%2 == 1){
                result++;
            }
            current = current >> 1;
        }
        return result;
#endif
        // 照慣例先處理為 0 的情況
        if(n == 0){
            return 0;
        }
        // 用一個特殊的方法, 稱為 Brian Kernighan’s 演算法
        // n 和 n-1 進行 AND, 可以消掉 n 本身最小的 1
        // 舉例, 10001000 -> n-1: 10000111 這樣 AND 之後, 原本的 1000 就會不見
        
        int index = 0;
        while(n != 0){
            n = n & (n-1);
            index ++;
        }
        return index;
    }
};
