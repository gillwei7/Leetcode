class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mag_char;
        for(int i = 0;i < magazine.length();i++) {
            mag_char[magazine[i]] ++;
        }
        for(int i = 0;i < ransomNote.length();i++) {
            if(mag_char.find(ransomNote[i]) != mag_char.end() && mag_char[ransomNote[i]]!=0 ) {
                mag_char[ransomNote[i]] --;
            }
            else {
                return false;
            }
        }
        return true;
    }
};