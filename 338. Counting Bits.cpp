class Solution {
public:
    // 題意: 計算 1 ~ n 每個數字的 binary 表示式 1 的數量, 回傳成 arrary
    // 一步一腳印法, 從 n 開始, 用 2 的餘數看目前的 bit 是否為 1, 然後一直進位, 直到變成 0
    // 所以每個 current 都需要一個 while loop, 也就是 log(n) 的計算時間
    vector<int> countBits(int n) {
        if(n == 0) {
            return{0};
        }
        int current = n;
        vector<int> index(n+1,0);
        while(current > 0){
            printf("current:%d\n",current);
            int temp = current;
            while(temp > 0) {
                printf("temp:%d\n",temp);
                if(temp%2 == 1){
                    index[current]++;
                }
                temp = temp >> 1;
            }
            current--;
        }
        return index;
        
    }
};
