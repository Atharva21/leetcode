class Solution {
private:
    int dp[10004];
public:
    Solution() {
        memset(dp, -1, sizeof(dp));
    }
    int numSquares(int n) {
        if(dp[n] != -1) return dp[n];
        if(sqrt(n) == (int)sqrt(n)) return dp[n] = 1;
        int k = 1;
        int ans = INT_MAX;
        while((k*k) <= n) {
            ans = min(ans, 1+numSquares(n-(k*k)));
            ++k;
        }
        return dp[n] = ans;
    }
};