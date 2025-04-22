class Solution {
public:
    int majorityElement(vector<int>& nums) {
#if 0
        // 直觀法: 用 hashmap 把 element 對應到的次數存起來
        // 只要某個 element 存起來的數量大於 n/2, 就表示這個 element 是 majority
        unordered_map<int,int> countNum;
        for(int i = 0;i < nums.size();i++){
            countNum[nums[i]]++;
            if(countNum[nums[i]] > n/2){
                return nums[i];
            }
        }
#else
        // Boyer-Moore Voting Algorithm
        // 在有個超過一半的數字的情況下才能用, 設定一個 candidate 和其 count
        // 如果遇到跟 candidate 一樣的就 +1, 如果不一樣就 -1
        // 但如果小於 0 的話就要換 candidate, 因為有超過半數的數字, 所以 candidate 就會是我們要的 result
        int count = 0;
        int candidate = 0;
        for(int i = 0;i < nums.size();i++){
            if(count == 0){
                candidate = nums[i];
            }
            if(nums[i] == candidate){
                count++;
            } else {
                if(count > 0){
                    count--;
                } else {
                    candidate = nums[i];
                    count = 1;
                }
            }
        }
        return candidate;
#endif
    }
};
