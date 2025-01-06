class Solution {
public:
   // bool backspaceCompare(string s, string t) {
        // // 暴力解法, 把兩邊有做 backspace 之後的 string 都記錄起來再做比較
        // // 一樣先檢查初始值其中一邊就是空字串的情形
        // if(s=="" && t == "")
        //     return true;
        // if(s=="" || t == "")
        //     return false;

        // // 利用 stack 特性, 只要有遇到'#' 就把最上面的那個 pop 出來, 不是'#'的話就
        // // push 進去
        // stack<char> s_stack;
        // stack<char> t_stack;
        // for(int i = 0;s[i]!=0;i++) {
        //     if(s[i] == '#') {
        //         if(!s_stack.empty()) {
        //             s_stack.pop();
        //         }
        //     }
        //     else {
        //         s_stack.push(s[i]);
        //         cout<<"s_stack:"<<s_stack.top()<<endl;
        //     }
            
        // }
        // for(int i = 0;t[i]!=0;i++) {
        //     if(t[i] == '#') {
        //         if(!t_stack.empty()) {
        //             t_stack.pop();
        //         }
        //     }
        //     else {
        //         t_stack.push(t[i]);
        //         cout<<"t_stack:"<<t_stack.top()<<endl;
        //     }
            
        // }
        // // 這裡直接對 stack 做比較, 
        // if(s_stack == t_stack)
        //     return true;
        // else
        //     return false;
//}
 bool backspaceCompare(string s, string t) {
        // 用雙指標來比較
        // 從前面開始比較的話會比較困難, 因為不確定後面有幾個#, 不知道可以從哪一個開始比 
        // 從後面開始還是比較容易 

        // 基本 nullptr 比較, 還是要先比一下初始狀態就為空的情形
        if(s=="" && t == "")
            return true;
        if(s=="" || t == "")
            return false;

        // 創一個 helper function, 可以傳目前要比較的 index 進去
        // 然後傳出實際可以做比較的 index 出來, 要注意 index < 0 的時候要 return false
        // 這裡放在迴圈裏面去檢查, 所以 while 條件必須是 index_S 或 index_T 為零
        int index_S = s.length() - 1;
        int index_T = t.length() - 1;

        while(index_S >= 0 || index_T >= 0) {
            index_S = nextValidChar(s, index_S);
            index_T = nextValidChar(t, index_T);
            char char_S = (index_S >= 0)? s[index_S]:'\0';
            char char_T = (index_T >= 0)? t[index_T]:'\0';
            if(char_S != char_T)
                return false;
            index_S--;
            index_T--;
        }
        return true;
    }

    int nextValidChar(string s, int index) {
        int backspace = 0;
        while(index >= 0) {
            // 遇到一般字元, 且沒有 backspace 可以用了, 直接 return 這個 index 即可
            if(s[index] != '#' && backspace == 0){
                break;
            }
            // 遇到'#', 累積 backspace
            else if(s[index] == '#') {
                backspace ++;
            }
            // 遇到一般字元, 且還有 backspace 可以用, 用掉一個
            else {
                backspace --;
            }
            index--;
        }
        return index;
    }
};

