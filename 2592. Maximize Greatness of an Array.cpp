class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        // 先將陣列重新排序成由小到大, 然後用雙指標
        // 對於每個 l, 找一個 r 剛好是比他大一點的, 或說是比他大的裡面最小的
        sort(nums.begin(), nums.end());
        int l = 0, r = 0, count = 0;
        int n = nums.size();

        
        while (r < n) {
            if (nums[r] > nums[l]) {
                count++;
                l++;
            }
            r++;
        }

        return count;

    }
};