class Solution {
public:
    bool isPalindrome(int x) {
        // 如果 x 是負的, 就像例子裡面提到的, 一定不符合條件
        // 另外如果 x 只有一個數字也可以分開處理, 因為一定符合條件
        if(x<0) {
            return false;
        } else if(x<10){
            return true;
        }
        // 設定一個 array 然後把數字不斷算 10 的餘數 push 進去
        // 記得終止迴圈的條件是 x != 0 不是 x/10 != 0, 不然會少算到最後一個數字
        vector<int> numbers;
        while(x != 0){
            numbers.push_back(x%10);
            x = x/10;
        }
        int length = numbers.size();
        for(int i = 0;i < length/2;i++){
            printf("numbers[%d]:%d numbers[%d]:%d\n\r", i, numbers[i], length-i-1,numbers[length-i-1]);
            // 這邊不管 array size 是偶數還是奇數, 只要計算到 length / 2 就可以
            if(numbers[i] != numbers[length-i-1]){
                return false;
            }
        }
        return true;
    }
};
