class Solution {
public:
    double champagneTower(int poured, int query_row, int query_col) {
        double dp[102][102];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = poured;
        for(int i=0; i<=query_row; ++i) {
            for(int j=0;j<=i;++j) {
                double q = (dp[i][j] - 1)/2.0;
                // cout << q << " ";
                if(q > 0) {
                    dp[i+1][j] += q;
                    dp[i+1][j+1] += q;
                }
            }
            // cout << endl;
        }
        return min(1.0, dp[query_row][query_col]);
    }
};