class Solution {
private:
    int dp[51][5];
    int getways(int n, int i=0) {
        if(i >= 5 || n < 0) return 0;
        if(n == 0) return dp[n][i] = 1;
        if(dp[n][i] != -1) return dp[n][i];
        int ans = 0;
        for(int j=i;j<5;++j) {
            ans += getways(n-1, j);
        }
        return dp[n][i] = ans;
    }
public:
    int countVowelStrings(int n) {
        memset(dp, -1, sizeof(dp));
        return getways(n);
    }
};