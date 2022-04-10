class Solution {
private:
    void printst(stack<int> st) {
        while(!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
    }
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto& s: ops) {
            if(s == "C") {
                st.pop();
            } else if(s == "D") {
                st.push(st.top() * 2);
            } else if(s == "+") {
                int last = st.top();st.pop();
                int second = st.top();st.pop();
                st.push(second);
                st.push(last);
                st.push(second+last);
            } else {
                st.push(stoi(s));
            }
            // cout << "for " << s << ": ";
            // printst(st);
        }
        
        int ans = 0;
        while(!st.empty()) {
            ans += st.top();st.pop();
        }
        return ans;
    }
};