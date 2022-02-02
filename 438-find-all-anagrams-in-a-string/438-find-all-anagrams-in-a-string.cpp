class Solution {
private:
    bool sameArray(vector<int> a, vector<int> b) {
        for(int i=0;i<26;++i) {
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        const int n = s.size();
        const int m = p.size();
        if(m > n) return {};
        vector<int> count(26, 0), current(26, 0), ans;
        for(auto& c: p) ++count[c-'a'];
        for(int i=0;i<m;++i) ++current[s[i]-'a'];
        if(sameArray(count, current))
            ans.push_back(0);
        for(int i=m;i<n;++i) {
            --current[s[i-m]-'a'];
            ++current[s[i]-'a'];
            if(sameArray(count, current))
                ans.push_back(i-m+1);
        }
        return ans;
    }
};