class Solution {
public:
    int hammingWeight(int n) {
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
        
    }
};
