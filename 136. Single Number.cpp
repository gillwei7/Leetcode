class Solution {
public:
    int singleNumber(vector<int>& nums) {
// 暴力法, 先把存到目前有的都存到 hash map
#if 0 
	// 使用 hashmap, 計算每個整數出現的次數
        // 最後再算出只有出現 1 次的那個整數
        // 這樣需要存整個 array 所以需要 O(n)
        // 另一個方式是可以只要有找到重複的就可以把原有存的整數刪掉
        // 但是因為最糟的 case 有可能我們需要存 n/2 的個數,
        // 這些整數最後才被取出來, 所以還是需要 O(n)
        unordered_map <int,int> countNum;
        int index = 0;
         while(index < nums.size()) {
            countNum[nums[index]]++;
            index++;
         }
        for (auto it = countNum.begin(); it != countNum.end(); ++it) {
            int number = it->first;  // Get the key (number)
            int count = it->second; // Get the value (count)

            if (count == 1) {
                std::cout << "Number: " << number << "\n";
                return number;
            }
        }
        return 0;

#else
        int result = nums[0];
        int index = 1;
        while(index < nums.size()) {
            result = result^nums[index];
            index++;
        }
        return result;
	
#endif
    }
};
