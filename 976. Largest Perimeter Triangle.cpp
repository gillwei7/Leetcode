class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        // 首先, 三角形的規則是最大的一邊要小於兩邊小的總和
        // Sorted or the biggest length 3 numbers
        sort(nums.begin(),nums.end());
        // 數字排序以後, 就可以從最大的開始看是否符合三角形
        for(int i = nums.size()-3;i >=0; i--){
            if(nums[i] + nums[i+1] > nums[i+2]){
                return (nums[i] + nums[i+1] +nums[i+2]);
            }
        }
        return 0;
    }
};