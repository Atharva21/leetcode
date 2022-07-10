class Solution {
private:
    int n;
    int dp[1002];
    vector<int> cost;
    int dfs(int i=0) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(dfs(i+1), dfs(i+2));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        this->cost = cost;
        n = cost.size();
        memset(dp, -1, sizeof(dp));
        return min(dfs(), dfs(1));
    }
};