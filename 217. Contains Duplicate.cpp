class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // 20241206
        // 使用 unordered hash set, 檢查每一個新增元素, 如果有重複的整個 function 就判定為真
        // 如果沒檢查到重覆的就加進去 hash set, 直到整個 vector 都檢查完, 沒有重複的便是 false 

        /*這邊 hash map 可以用 hash set 代替 */
        //unordered_map <int, int> nums_storage;
        unordered_set <int> nums_storage;
        for(int i = 0;i < nums.size(); i++) {
            if(nums_storage.find(nums[i]) == nums_storage.end()) {
                //nums_storage[nums[i]]++; // 用 hash set 代替
                nums_storage.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;

    }
};