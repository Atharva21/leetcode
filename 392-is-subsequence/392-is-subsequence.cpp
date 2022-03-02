class Solution {
public:
    bool isSubsequence(string s, string t) {
        const int m = s.size();
        const int n = t.size();
        if(m > n) return false;
        if(m == 0) return true;
        if(n == 0) return true;
        int i=0, j=0;
        while(i < m && j < n) {
            while(j < n && t[j] != s[i]) ++j;
            if(j == n) return false;
            
            // s[i] == t[j].
            ++i;
            ++j;
        }
        if(i < m) return false;
        return true;
    }
};