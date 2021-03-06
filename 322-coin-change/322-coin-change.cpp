class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp;
        dp.resize(amount+1, amount+1);
        dp[0] = 0;
        for(int i=0;i<amount+1;++i) {
            for(auto& coin: coins) {
                if(coin > i) continue;
                dp[i] = min(dp[i], 1+dp[i-coin]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};