class Solution {
public:
    int missingNumber(vector<int>& nums) {
        #if 0
        int n = nums.size();
        int result;
        // 這裡把有遇到的數字加進去,
        unordered_map<int,bool> hashMap;
        for(int i = 0;i < n;i++) {
            hashMap[nums[i]] = true;
        }
        
	// 檢查從 0 到 n 之中, 在 hashMap 找不到的數字
	// 這裡如果是用直接找 hashMap 之中為 false 的數字, 會找不到
	// 因為從來沒有被加入過
	// 所以必須用 find() == end() 來尋找裡面沒有的
	
        for (int i = 0; i <= n; ++i) {
            if (hashMap.find(i) == hashMap.end()) {
                return i; // Missing number
            }
        }
        return -1;
        #else
        int length = nums.size();
        int result = length* (length+1)/2;
        for(int i = 0;i < nums.size();i++) {
            result = result - nums[i];
        }
        return result;

        #endif

    }
};
