class Solution {
public:
    int longestPalindrome(string s) {
        int oddCount; // 數量是奇數的字元
        unordered_map<char, int> ump; //記錄每個字源的數量
        for(char ch:s) // 對於字串中每個字元的迴圈
        {
            ump[ch]++;
            // 每個字元都檢查一下現在是奇數還是偶數
            if(ump[ch] %2 == 1)
            {
                oddCount ++;
            }
            else
            {
                oddCount --;
            }
        }
        // 如果字元數字裡面有奇數, 就只能保留一個, 把其他的扣掉
        if(oddCount >1)
        {
            return s.length() - oddCount + 1;
        }
        return s.length();
        
    }
};