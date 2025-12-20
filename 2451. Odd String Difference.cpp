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
};