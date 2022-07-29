class Solution {
private:
    bool match(string s, string pattern) {
        const int n = s.size();
        const int m = pattern.size();
        if(m != n) return false;
        unordered_map<char, char> mp, rev;
        for(int i=0;i<n;++i) {
            char c = s[i];
            char p = pattern[i];
            if(mp.find(c) != mp.end()) {
                if(mp[c] != p) return false;
            }
            if(rev.find(p) != rev.end()) {
                if(rev[p] != c) return false;
            }
            if(mp.find(c) == mp.end() && rev.find(p) == rev.end()) {
                mp[c] = p;
                rev[p] = c;
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        for(auto& word: words) {
            if(match(word, pattern)) ans.push_back(word);
        }
        return ans;
    }
};