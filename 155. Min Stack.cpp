class MinStack {
public:
    MinStack() {
        // 不能在 Constructor 裡面建這兩個 stack
        // stack<int> fullStack;
        // stack<int> minStack;
        // 因為這樣這兩個 stack 只有在執行 contructor function 的時候存在, 後面要做 operation 的時候就不在了
        // 要在 private member 裡面去建
    }
    
    void push(int val) {
        fullStack.push(val);
        if(minStack.empty() || min(minStack.top(),val) == val){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(fullStack.top() == minStack.top()){
            fullStack.pop();
            minStack.pop();
        }else{
            fullStack.pop();
        }
    }
    
    int top() {
        return fullStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> fullStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */