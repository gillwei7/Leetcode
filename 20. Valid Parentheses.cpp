class Solution {
public:
    bool isValid(string s) {
        stack<char> sc;
        for(int i=0; i < s.length(); i++)
        {
            // stack 最開始必須是open, 加入stack 
            if(s[i] == '(' || s[i] == '{' || s[i] == '[' )
            {
                sc.push(s[i]);
            }
            else
            {
                // 不是open bracket
                // 若不是open bracket 但stack 裡面又不是空的, return false
                if(!sc.empty())
                {
                    // 如果是close 的話, stack 最前面必須是對應的open bracket
                    // 如果是的話就把open那個pop出來, 消除掉
                    if((s[i] == ')' && sc.top() == '(') || (s[i] == ']' && sc.top() == '[') || (s[i] == '}' && sc.top() == '{'))
                    {
                        sc.pop();
                    }
                    // 不是open bracket 又沒辦法close掉, return false
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(sc.empty() == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};