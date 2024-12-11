class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
        // 檢查字串是否為空, 為空的話返回空字串
        if(strs.empty()) return "";
        // 只要用第一個字串拿來跟其他的字串檢查即可
        string prefix = strs[0];
        // 有兩種方法, 一種是用一個空字串, 比對所有字串的某字元相同就加入
        // 這裡用的是比對第一個字串和其他所有字串, 只要不完全一樣就從最後面開始刪減一個字元
        for(int i = 1;i < strs.size(); i++) {
            while(strs[i].find(prefix) != 0) {
                prefix = prefix.substr(0, prefix.size() - 1);
                if(prefix.empty()) return "";
            }
        }
        return prefix;
    }
};