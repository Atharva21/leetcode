class MyStack {
private:
    queue<int> q1, q2;
    void flip() {
        while(q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        // queue<int> q3=q1, q4=q2;
        // cout << "q1: ";
        // while(!q3.empty()) {
        //     cout << q3.front() << " ";
        //     q3.pop();
        // }
        // cout << "q2: ";
        // while(!q4.empty()) {
        //     cout << q4.front() << " ";
        //     q4.pop();
        // }
    }
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        flip();
        int ans = q1.front();
        q1.pop();
        swap(q1, q2);
        return ans;
    }
    
    int top() {
        flip();
        return q1.front();
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