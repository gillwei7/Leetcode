class Solution {
public:
    string oddString(vector<string>& words) {
        // 拿 words[0] 當作基準, 會有兩種情況, 第一種是 words[0] 剛好就是 odd string
        // 第二種是其他的 words[] 是 odd string
        // 用一個 double loop 來確認兩個 string 字元之間的 difference 是否不同
        // 然後用一個變數來標註跟 words[0] 不一樣的字串個數, 如果大於 2 的話, words[0] 就一定是 odd string 了
        // 因為表示 words[0] 和另外兩個都不一樣, 那 words[0] 就是那個 odd string, 這時候可以直接 return words[0]
        string result = words[0];
        int diffCount = 0;
        // vector 裡面的尺寸用 size, string 尺寸用 size
        for(int i = 1;i < words.size();i++){
            bool isDifferent = false;
            // 小心字元 j+1 不能超過 string size
            for(int j = 0;j < words[0].size()-1;j++){
                if(words[i][j+1] - words[i][j] != words[0][j+1] - words[0][j]){
                    isDifferent = true;
                    break;
                }
            }
            if(isDifferent){
                diffCount++;
                // 如果 diffCont 大於等於 2, 表示 words[0]肯定是 odd string, 後面就不用比了
                if(diffCount >= 2){
                    return words[0];
                }
                result = words[i];
            }
        }
       
        return result;
    }
    // 程式可以再優化, 只要比較到第三個就知道 words[0] 是不是 odd string
    // 只要 words[0] 不是 odd string, 那麼只要比較到下一個 string 跟 words[0]
    // 不一樣的情況, 那個 string 就一定是 odd string
    #if 0
    string oddString(vector<string>& words) {
        int n = words[0].size();

        // Helper function to compare difference arrays of two strings
        auto sameDiff = [&](const string& a, const string& b) {
            for (int i = 0; i + 1 < n; i++) {
                if (a[i + 1] - a[i] != b[i + 1] - b[i]) {
                    return false;
                }
            }
            return true;
        };

        // Compare difference patterns among first three strings
        bool d01 = sameDiff(words[0], words[1]);
        bool d02 = sameDiff(words[0], words[2]);

        // If words[0] differs from both, it must be the odd string
        if (!d01 && !d02) {
            return words[0];
        }

        // Otherwise, determine the correct (common) pattern
        string& reference = d01 ? words[0] : words[1];

        // Find the odd string by comparing with the reference
        for (int i = 0; i < words.size(); i++) {
            if (!sameDiff(reference, words[i])) {
                return words[i];
            }
        }

        // Guaranteed to find one by problem statement
        return "";
    }
    #endif
};