class Solution {
public:
    string removeDuplicates(string st, int k) {
        stack<pair<char, int>> s;
        for(auto& c: st) {
            if(s.empty() || s.top().first != c) {
                s.push({c, 1});
                continue;
            }
            auto top = s.top();
            if(top.second == k-1) {
                s.pop();
                continue;
            }
            s.pop();
            s.push({c, top.second+1});
        }
        string ans = "";
        while(!s.empty()) {
            auto top = s.top();s.pop();
            string sub = "";
            for(int i=0;i<top.second;++i) {
                sub += top.first;
            }
            ans = sub + ans;
        }
        return ans;
    }
};