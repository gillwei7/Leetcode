class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> result;
        for(int i = 0; i < tokens.size(); i ++)
        {
            if(tokens[i] == "+"||tokens[i] =="-" || tokens[i] == "*" || tokens[i] == "/" )
            {
                int num_2 = result.top();result.pop();
                int num_1 = result.top();result.pop();
                if(tokens[i] == "+") result.push(num_1 + num_2);
                if(tokens[i] == "-") result.push(num_1 - num_2);
                if(tokens[i] == "*") result.push(num_1 * num_2);
                if(tokens[i] == "/") result.push(num_1 / num_2);
            }
            else
            {
                result.push(stoi(tokens[i]));
            }
        }
        return result.top();
    }
};