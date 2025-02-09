class Solution {
public:
    bool isPalindrome(int x) {
    #if 0
        // 首先如果 x 是負的, 就像例子裡面提到的, 一定不符合條件
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
    #else
        // 首先如果 x 是負的, 就像例子裡面提到的, 一定不符合條件
        // 另外如果 x 尾數是 0, 除了 0 本身符合條件, 其他都會造成實際少一個數字
        // 例如 9890, 倒過來是 0989 一定不符合
        if (x < 0 || (x % 10 == 0 && x != 0)) {
        return false;
         }

        int reverseNum = 0;
        while(x > reverseNum){
            reverseNum = reverseNum*10 + x%10;
            x = x/10;
        }
        // 如果十位數總共有奇數個, 例如 12331, 最後 reverseNum 會變 133
        // 也就是從後面數來共三個, x 會變 12, 所以檢查 reverseNum / 10 跟 x 是否相同
        // 如果十位數總共有偶數個, 例如 1231, 最後 reverseNum 會變 13, x 會變 12
        // 檢查兩者是否相同即可
        return (reverseNum/10 == x || reverseNum == x);
    #endif
    }
};
