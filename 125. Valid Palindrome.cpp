class Solution {
public:
    bool isPalindrome(string s) {
        // 先將string 裡面的空白和非字母數字的字元去掉
        string nstr;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (isalnum(c))
            {
                nstr += tolower(c);
            }
        }
        // 再比對儲存字串裡面的低指針和高指針是否相同即可
        int left = 0, right = nstr.size() - 1;
        while (left < right)
        {
            if (nstr[left] != nstr[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};