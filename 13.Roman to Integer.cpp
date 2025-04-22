class Solution {
public:
    
    int romanToInt(string s) {
        int result = 0;
        // 創立一個 hashmap 可以對應羅馬數字對於阿拉伯數字
        // 這樣就可以從裡面去比較大小 
        unordered_map<char,int> romanMap =
        {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        // 因為題目只會給 Valid Roman number, 所以可以只比較對應的阿拉伯數字大小
        // 如果目前這個比下一個小的話, 就算是負的, 不然就算是正的
        // 這邊因為一直要比較下一個, 所以不會加到最尾巴那個, 後面記得要加上去
        for(int i = 0;i < (s.length()-1);i++){
            if(romanMap[s[i]] < romanMap[s[i+1]]) {
                result -= romanMap[s[i]];
            }
            else {
                result += romanMap[s[i]];
            }
        }
        // 最後一個羅馬數字一定是正的
        result += romanMap[s[s.length()-1]];
        return result;
    }
};
