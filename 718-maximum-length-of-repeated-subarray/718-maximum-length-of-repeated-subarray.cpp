class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        const int n1 = v1.size();
        const int n2 = v2.size();
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
        int ans = 0;
        for(int i=n1-1;i>=0;--i) {
            for(int j=n2-1;j>=0;--j) {
                if(v1[i] == v2[j]) {
                    dp[i][j] = 1 + dp[i+1][j+1];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};