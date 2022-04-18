class MyStack {
private:
    queue<int> q1, q2;
    void shift() {
        while(q1.size() > 1) {
            int x = q1.front();
            q1.pop();
            q2.push(x);
        }
        swap(q1, q2);
    }
public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q2.size()) {
            int x = q2.front();
            q2.pop();
            q1.push(x);
        }
        q1.push(x);
    }
    
    int pop() {
        if(!q2.size())
            shift();
        int ans = q2.front();
        q2.pop();
        return ans;
    }
    
    int top() {
        if(!q2.size())
            shift();
        int ans = q2.front();
        return ans;
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */