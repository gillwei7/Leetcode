class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map <int, int> nums_storage;
        for(int i = 0;i < nums.size(); i++) {
            if(nums_storage.find(nums[i]) == nums_storage.end()) {
                nums_storage[nums[i]]++;
            }
            else{
                return true;
            }
        }
        return false;

    }
};