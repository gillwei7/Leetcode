class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
        // 檢查字串是否為空, 為空的話返回空字串
        if(strs.empty()) return "";
        // 如果 strs 裡面只有一個字串, 就直接返回它
        if(strs.size() == 1) return strs[0];
        // 有兩種方法, 一種是用一個空字串, 比對所有字串的某字元相同就加入
        // 這裡用的是比對第一個字串和其他所有字串, 只要不完全一樣就從最後面開始刪減一個字元
        #if 0
        // 只要用第一個字串拿來跟其他的字串檢查即可
        string prefix = strs[0];
        for(int i = 1;i < strs.size(); i++) {
            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if(prefix.empty()) return "";
            }
        }
        return prefix;
        #else
        // 第二種方式, 用一個空字串, 比對所有字串的某字元相同就加入
        int index = 0;
        int n = strs[0].length();
        string result = ""; // 有可能是空字串, 所以要先初始化為空
        // index 不斷往後比對, 記得在迴圈裡面要 ++ 
        while(index < n){
            char currentChar = strs[0][index];
            for(int i = 1;i < strs.size();i++){
                // 由於目前比對的 index 有可能比目前比對的 string 長度還長
                // 如果目前 string 沒有到這個 index 就要 return result 了
                if(index >= strs[i].length() || currentChar != strs[i][index]){
                    return result;
                }
            }
            // 比對每個字串都沒問題的話, 就把目前這個字元加上去
            result += currentChar;
            index++;
        }
        return result;
        #endif
    }
};