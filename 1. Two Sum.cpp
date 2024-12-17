class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // 這裡要創一個兩個 integer 的 hash map, 不能創建只有一個的, 因為 index 也要記錄下來, 到時候要回傳用的
        unordered_map<int,int> hash_map;
        // 最後的結果也是要用 vector 回傳, 長度固定是 2
        vector<int> result;
        // 先確認序列裡每個數字跟 target 的差異值, 用這個數字往回找是否出現過
        int complement;
        for(int index = 0; index < nums.size(); index++) {
            complement = target - nums[index];
            // 跟 target 的差異沒有出現過, 目前 nums[index] 加入 hash_map
            // 這邊注意怎麼加入 index 的 hash_map[key] = value
            if(hash_map.find(complement) == hash_map.end()) {
                hash_map[nums[index]] = index;
            }
            // 跟 target 的差異有出現過, 可以直接回傳目前 index 和在 hash_map 裡面找到的
            else {
                result.push_back(index);
                result.push_back(hash_map[complement]);
                return result;
            }
        }
        return result;
    }
};
