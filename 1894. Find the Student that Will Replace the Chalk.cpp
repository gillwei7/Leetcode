class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        // int result;
        // result  = k - chalk[0];
        // result -= chalk[1]; .... result -= chalk[n-1];
        // 輪迴這個 array, 從 0 開始把 k 減掉, 減到小於 0 就 return, 不然如果一直減到最後面就重新從 0 開始
        int result = k;
        int array_sum = 0,array_rotate = 0;
        int index = 0;
        int length = chalk.size();

        while(result > 0){
            if(result - chalk[index] >= 0){
               result -= chalk[index];
               if(array_rotate){
                    array_sum += chalk[index];
               } 
            }else{
                return index;
            }
            index++;
            if(index >= length){
                // 如果沒有輪迴過 array, 就把 flag 設起來
                // 如果已經有輪迴過 array 了, 確認是否 k 還是大於整個 array 的和
                if(array_rotate == 0){
                    array_rotate = 1;
                }else{
                    if(result >= array_sum){
                        result %= array_sum;
                    }
                }
                index = 0;
            }
        }
        return index;
    }
};