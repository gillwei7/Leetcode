class Solution {
    public:
        bool isPalindrome(string s) {
            // 使用左右指標法, 左邊和右邊指標一直去比較是否相同, 然後逼近中間
            int l = 0;
            int r = s.length()-1;
            // 這裡可以不用 l <= r, 中間那個字可以不算
            // 要用到兩個 api, isalnum: 檢查字元是否為數字或字母, tolower: 將大寫字母改為小寫字母
            // 只要不是 isalnum 就直接略過, 最後檢查的時候則用 tolower 將大寫字母改成小寫 
            while(l < r){
                while( (l < r) && !isalnum(s[l]) ){
                    l++;
                }
                while( (l < r) && !isalnum(s[r]) ){
                    r--;
                }
                if( tolower(s[l]) != tolower(s[r]) ){
                    return false;
                }
                l++;
                r--;
            }
            return true;
            
        }
    };