class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        map<char, char> mp;
        mp['['] = ']';
        mp['{'] = '}';
        mp['('] = ')';
        stack<char> st;
        for(char c: s) {
            if(c == '[' || c == '{' || c == '(') {
                st.push(c);
            } else {
                if(st.empty()) return false;
                char d = st.top();st.pop();
                if(mp[d] != c) return false;
            }
        }
        return st.empty();
    }
};