class Solution {
private:
    int m, n;
    int dp[55][55][51];
    vector<pair<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    bool valid(int i, int j) {
        return i>=0&&i<m&&j>=0&&j<n;
    }
    int dfs(int i, int j, int moves) {
        if(dp[i+1][j+1][moves] != -1) return dp[i+1][j+1][moves];
        if(!valid(i, j)) return dp[i+1][j+1][moves] = 1;
        if(!moves) return dp[i+1][j+1][moves] = 0;
        long long ans = 0;
        // cout << "for: " << i << " " << j << " " << moves << endl;
        for(auto& dir: dirs) {
            ans += dfs(i+dir.first, j+dir.second, moves-1);
        }
        // cout << "ans is " << ans << endl << endl;
        return dp[i+1][j+1][moves] = ans % (int)(1e9+7);
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m;
        this->n = n;
        memset(dp, -1, sizeof(dp));
        return dfs(startRow, startColumn, maxMove);
    }
};