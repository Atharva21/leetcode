class Solution {
private:
    void clearStack(stack<char>& st) {
        while(!st.empty()) st.pop();
    }
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int ans = 0;
        for(auto& c: s) {
            if(c == '(') {
                st.push(-1);
            } else {
                int nested = 0;
                bool openFound = false;
                while(!st.empty()) {
                    if(st.top() == -1) {
                        openFound = true;
                        break;
                    }
                    nested += st.top();st.pop();
                }
                if(!openFound) continue;
                st.pop();
                st.push(nested+2);
                int adj=0;
                while(!st.empty() && st.top() != -1) {
                    auto tp = st.top();st.pop();
                    adj += tp;
                    ans = max(ans, adj);
                }
                st.push(adj);
            }
        }
        return ans;
    }
};