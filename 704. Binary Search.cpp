class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l = 0;
       int r = nums.size()-1;
       printf("left=%d, right=%d\r\n", l, r);
        // 這裡除了r>l的情況之外, 要小心 r為l+1的情況也要跳出來, 避免一直反覆橫跳 
        while((r != l+1) && (r > l))
        {
            // 這裡 l + (r-l)/2 其實就是 (l+r)/2 但是可以避免l+r 有可能溢出的情況
            if(target > nums[l + (r-l)/2])
            {
                l = l + (r-l)/2;
            }
            else
            {
                r = l + (r-l)/2;
            }
            printf("r=%d, l=%d\r\n", r, l);
        }
        //這裡記得用 if... else if 把所有情況列下來
       if(target == nums[l])
            return l;
       else if(target == nums[r])
            return r;       
        else
            return -1;
    }
};