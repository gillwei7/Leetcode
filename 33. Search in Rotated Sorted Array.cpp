class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 題意是找出 target, 且規定時間複雜度 O(N), 基本表示就是用二元搜尋法
        // 二元搜尋的方式是有 left, right 和 middle, 且確認完 middle 後就要知道下一步要往左還是往右搜尋
        // 需要在紙上先畫示意圖
        // 在這個題目裡面, middle有兩種可能性, 可能在左邊的上升區間或是右邊的上升區間, 情況不同
        // 然後要確認 target 在 middle 左邊或右邊, 才能決定要修改 l 還是修改 r pointer
        int l = 0;
        int r = nums.size()-1;
        while( l <= r) {
            int mid = (l+r)/2;
            if(target == nums[mid]) {
                return mid;
            }
            // middle 在左邊的上升區間
            if(nums[l] <= nums[mid]) {
                // target 在 middle 右邊
                if(target > nums[mid] || target < nums[l]) {
                    l = mid + 1;
                }
                // target 在 middle 左邊
                else {
                    r = mid -1;
                }
            }
            // middle 在右邊的上升區間
            else {
                // target 在 middle 左邊
                if(target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                }
                // target 在 middle 右邊
                else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};