class Solution {
public:
    int minOperations(vector<int>& nums) {
        // 首先可以先算出每個數字的 count, 因為只要有 1 的就必定是湊不出來
        int ans = 0;
        unordered_map<int, int> m;
        for(auto num : nums){
            m[num]++;
        }
        for(auto const& [num, cnt] : m){
            // 某個數字是只有一個, 必定是湊不出來
            if(cnt == 1){
                return -1;
            // 先全部用 3 去湊，最後剩 1 的時侯就把前一次的 3 拿回來用 2 個 2 去湊
            // 這樣就可以湊出全部的數字
            // 舉例: 5 = 2 + 3
            // 6 = 3 + 3
            // 7 = 2 + 2 + 3 就是把第一個 3 改成 2 + 2
            } else {
                ans += cnt/3;
                if(cnt % 3 != 0){
                    ans++;
                }
            }
            return ans;
        }
    }
};