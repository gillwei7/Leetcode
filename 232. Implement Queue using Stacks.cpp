class MyQueue {
public:
    stack<int> s1; // 用來 push 的 
    stack<int> s2; // 用來 pop / peek 的
    
    MyQueue() {
        // Do nothing?
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        int result;

        if(!s2.empty()) {
            // stack pop 的值沒辦法直接 return 出來, 所以需要先 top() 存起來
            // 之後再 pop 掉
            result = s2.top();
            s2.pop();
            return result;
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            result = s2.top();
            s2.pop();
            return result;
        }
    }
    
    int peek() {
        if(!s2.empty()) {
            return s2.top();
        }
        else {
            while(!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            return s2.top();
        }
    }
    
    bool empty() {
        if( s1.empty() && s2.empty() )
            return true;
        else
            return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */