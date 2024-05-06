class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> storage;
        for(int i=0; i < nums.size();i++) {
            storage[nums[i]]++;
            if(storage[nums[i]] > nums.size()/2) {
                return nums[i];
            }
        }
        return 0;
        
    }
};