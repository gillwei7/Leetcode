class Solution {
public:
    int myAtoi(string s) {
        int s_length = s.length();
        int ifResultPositive = 1;
        bool ifDigitCountStart = false;
        long result = 0;
        int temp_digit;
        for(int i =  0; i < s_length; i++)
        {
            if(ifDigitCountStart == false )
            {
                if(s[i] == ' ')
                {
                    continue;
                }
                else if(s[i] == '+')
                {
                    ifResultPositive = 1;
                    continue;
                }
                else if(s[i] == '-')
                {
                    ifResultPositive = -1;
                    continue;
                }
                else if(s[i] < '0' || s[i] > '9')
                {
                    return 0;
                }

                if(s[i] >= '1' && s[i] <= '9')
                {
                    ifDigitCountStart = true;
                    temp_digit = s[i] - '0';
                    result = result * 10 + temp_digit; 
                }
                if(s[i] == '0')
                {
                    continue;
                }
            }
            // ifDigitCountStart == true
            else
            {
                if( s[i] >= '0' && s[i] <= '9' )
                {
                    temp_digit = s[i] - '0';
                    result = result * 10 + temp_digit; 
                    if(result > INT_MAX)
                    {
                        break;
                    }
                }
                else
                {
                    return (int)result * ifResultPositive;
                }
            }
            printf("i:%d %d\r\n",i, result);
        }
        if ((int) result != result) 
        {
            return ifResultPositive == 1 ? INT_MAX : INT_MIN;
        }
        return (int)result * ifResultPositive;
    }
};