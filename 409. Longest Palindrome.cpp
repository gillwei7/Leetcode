class Solution {
    public:
        int longestPalindrome(string s) {
            // 最重要的是奇數個數的字母, 只能存一個多出來的, 偶數個數的則可以全部存
            // 例如 aaaccc, 除了 aacc 可以直接存, 多出來的 a 和 c, 最後也只能存一個
            // 這邊先用 hashmap 把全部存起來, 然後先把全部的字數都加到結果
            // 奇數的部分如果大於 1 的話就要把其他的減掉
            unordered_map<char,int> hashChar;
            for(int i = 0;i < s.length();i++){
                hashChar[s[i]]++;
            }
            int oddCount = 0;
            int result = s.length();
    
            // hashmap 的 for 迴圈語法要記得
            for(auto& pair: hashChar){
                if(pair.second%2){
                    oddCount++;
                }
            }
            
            if (oddCount > 1) {
                result -= (oddCount - 1);
            }
            return result;
        }
    };