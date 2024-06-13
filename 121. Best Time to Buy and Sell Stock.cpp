class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int maxProfit = 0;
        int currentProfit = 0;
        while(r < prices.size()) {
            if(prices[l] < prices[r]) {
                currentProfit = prices[r] - prices[l];
                maxProfit = max(maxProfit, currentProfit);
            }
            else {
                l  = r;
            }
            r++;   
        }
        return maxProfit;
    }
};