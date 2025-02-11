class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 可能會有只有零個或是只有一個的輸入, 先處理掉
        if(prices.size() == 0 || prices.size() == 1){
            return 0;
        }
        int l = 0;
        int r = 1;
        int result = prices[1]-prices[0]; // 這邊不能用 prices[r] - prices[l]
        // 以右指標為基準一直往右數, 
        // 如果新的右指標比原本左指標小, 就把左指標置換掉
        // 如果新的右指標減左指標計算起來會比原本的結果大, 就置換掉原來的結果
        while(r < prices.size()){
            if(prices[r] < prices[l]) {
                l = r;
            } else if((prices[r] - prices[l]) > result){
                result = prices[r]-prices[l];
            }
            r++;
        }
        // 結果有可能是負的, 要過濾這種情況
        if(result > -1){
            return result;
        } else {
            return 0;
        }

    }
};
