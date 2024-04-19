class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int carry = 0;
        int val = 0;
        int a_size = a.size();
        int b_size = b.size();
        string res = "";

        for(int i = 0; i < max(a_size, b_size);i++) {
            val = carry;
            // 如果目前計算的數目
            if(i < a_size) {
                val += (a[i]-'0');    
            }
            if(i < b_size) {
                val += (b[i]-'0');    
            }
            carry = val/2;
            val = val%2;
            res += ('0' + val);
        }
        if(carry) {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return res;
    }
};