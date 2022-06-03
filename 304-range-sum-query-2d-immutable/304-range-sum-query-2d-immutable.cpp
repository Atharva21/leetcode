class NumMatrix {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = m == 0 ? 0 : matrix[0].size();
        dp.resize(m+1, vector<int>(n+1, 0));
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                dp[i+1][j+1] = dp[i][j+1] + dp[i+1][j] - dp[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = dp[row2+1][col2+1];
        if(col1 > 0) {
            // not connected to left edge.
            ans -= (dp[row2+1][col1]);
        }
        if(row1 > 0) {
            // not connected to the top.
            ans -= (dp[row1][col2+1]);
        }
        if(col1 > 0 && row1 > 0) {
            ans += dp[row1][col1];
        }
        // cout << ans << endl;
        // cout << dp[row1][col1];
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */