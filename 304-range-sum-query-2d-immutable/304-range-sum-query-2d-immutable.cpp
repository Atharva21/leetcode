class NumMatrix {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = m == 0 ? 0 : matrix[0].size();
        dp.resize(m, vector<int>(n+1, 0));
        for(int i=0;i<m;++i) {
            for(int j=1;j<=n;++j) {
                dp[i][j] = dp[i][j-1] + matrix[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i=row1;i<=row2;++i) {
            ans += dp[i][col2+1] - dp[i][col1];
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */