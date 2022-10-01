class Solution {
private:
    int dp[101];
    int n;
    int dfs(const string& s, int i=0) {
        if(i >= n) return 1;
        if(s[i] == '0') return dp[i] = 0;
        if(dp[i] != -1) return dp[i];
        
        int chooseOne = 0, chooseTwo = 0;
        chooseOne = dfs(s, i+1);
        if(i+1 < n && s[i] < '3') {
            if(s[i] < '2' || s[i+1] < '7') {
                chooseTwo = dfs(s, i+2);
            }
        }
        
        return dp[i] = chooseOne + chooseTwo;        
    }
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        n = s.size();
        return dfs(s);
    }
};