class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        if(n < 2) return 0;
        int dp0 = cost[n-1];
        int dp1 = 0;
        for(int i=n-2;i>=0;--i) {
            int cur = cost[i] + min(dp0, dp1);
            dp1 = dp0;
            dp0 = cur;
        }
        return min(dp1, dp0);
    }
};