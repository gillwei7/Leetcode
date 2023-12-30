class Solution {
public:
    bool isValid(string s) {
    //創一個stack 一個一個儲存前括號, 然後如果有後括號就把對應的前括號消掉
    //最後只要stack 是空的就對了, 否則就是錯
    //不能用unordered_map, 因為有穿插的前括號和後括號的話, 還是算不對
        stack<char> sc;
        int i = 0;
        while(i<s.size())
        {
            //如果遇到前括號就放進去 
            if(s[i]=='(' || s[i]=='{' || s[i]=='[') sc.push(s[i]);
	    // 如果遇到後刮號就要檢查現在最上面是不是對應的前括號, 否則順序就不對了
	    // 例如: "({)}" 這個就算不對
            if(s[i]==')')
            {
	    	// 這邊要檢查如果一開始就遇到後括號就不對了
                if(sc.empty() == true)
                    return false;
                if(sc.top() == '(')
                    sc.pop();
                else
                    return false;
            }
            if(s[i]=='}')
            {
                if(sc.empty() == true)
                    return false;
                if(sc.top() == '{')
                    sc.pop();
                else
                    return false;
            }
            if(s[i]==']')
            {
                if(sc.empty() == true)
                    return false;
                if(sc.top() == '[')
                    sc.pop();
                else
                    return false;
            }
            i++;
        }
        if(sc.empty() == true)
            return true;
        else
            return false;
    }
};
