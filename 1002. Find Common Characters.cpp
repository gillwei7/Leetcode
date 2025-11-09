#include <vector>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        // 題解是要計算 26 個字母裡面各被算了幾次
        // 所以初始化一個 26 個數字的 array, 都初始化成 INT_MAX 就可以跟到時候算出來的比較
        // 然後直接取最小值
        vector<int> ans(26, INT_MAX);
        for(auto& word : words){
            vector<int> cnt(26,0);
            for(char c: word){
                cnt[c - 'a']++;
            }
            // 把結果的陣列, 更新成每個 char 數字的最小值
            for(int i = 0;i < 26;i++){
                ans[i] = min(ans[i],cnt[i]);
            }
        }
        // 重新把數字的陣列轉化成原本的字串
        vector<string> ans_string;
        for(int i = 0;i < 26;i++){
            for(int j = 0;j < ans[i];j++){
                ans_string.push_back(string(1,'a'+i));
            }
        }
        return ans_string;
    }
};