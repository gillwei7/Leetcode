class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 由於已經排好順序了
        // 設定兩個指標, 最前面和最後面, 然後把數字加起來
        // 如果太小就把最前面的++, 如果太大就把最後面的--
        // 題目有說只會有一個正確答案, 所以不用考慮數字重複的問題, 如果有重複的話就要在hi-- 和 lo++那邊處理
        int lo = 0;
        int hi = numbers.size() - 1;
        int cur;
        while(lo < hi) {
            cur = numbers[lo] + numbers[hi];
            if( target == cur ) {
                return { lo+1, hi+1 };
            }
            else if( cur > target ){
                hi--;
            }
            else if( cur < target) {
                lo++;
            }
        }
        return { -1, -1};
    }
};