class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1);
        dp[0] = false;
        for(int i=1;i<=n;++i) {
            bool found = false;
            for(int j=1;pow(j, 2) <= i;++j) {
                if(!dp[i-pow(j, 2)]) {
                    found = true;
                    break;
                }
            }
            dp[i] = found;
        }
        return dp[n];
    }
};