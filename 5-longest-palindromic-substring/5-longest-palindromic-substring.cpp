class Solution {
public:
    string longestPalindrome(string s) {
        const int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start, maxlen;
        for(int i=0;i<n;++i) {dp[i][i] = true;start=i;maxlen=1;}
        for(int i=0;i+1<n;++i) if(s[i] == s[i+1]) {dp[i][i+1] = true;start=i;maxlen=2;}
        for(int k=3;k<=n;++k) {
            for(int i=0;i+k-1<n;++i) {
                int j = i+k-1;
                if(dp[i+1][j-1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if(k > maxlen) {
                        maxlen = k;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxlen);
    }
};