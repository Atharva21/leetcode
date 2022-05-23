class Solution {
private:
    string s;
    int n;
    int palindromeCount(int l, int r) {
        int ans = 0;
        while(l >= 0 && r < n) {
            if(s[l--] == s[r++])
                ++ans;
            else
                break;
        }        
        return ans;
    }
public:
    int countSubstrings(string s) {
        this->s = s;
        n = s.size();
        int ans = n;
        for(int i=0;i<n;++i) {
            ans += palindromeCount(i-1, i+1);
            ans += palindromeCount(i, i+1);
        }
        return ans;
    }
};