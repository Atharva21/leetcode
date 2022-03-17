class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(auto& c: s) {
            if(c == '(') {
                st.push(-1);
            } else {
                if(st.top() == -1) {
                    ans = 1;
                    st.pop();
                    st.push(ans);
                    continue;
                }
                int k = 0;
                while(st.top() != -1) {
                    k += st.top();
                    st.pop();
                }
                st.pop();
                ans = k*2;
                st.push(ans);
            }
        }
        int k = 0;
        while(!st.empty()) {
            k += st.top();
            st.pop();
        }
        if(k != 0) ans = k;
        return ans;
    }
};