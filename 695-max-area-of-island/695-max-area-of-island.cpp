class Solution {
private:
    vector<vector<int>> grid;
    vector<vector<bool>> vis;
    int m, n;
    vector<pair<int, int>> dirs = {
        {1, 0},
        {0, 1},
        {-1, 0},
        {0, -1}
    };
    bool valid(int i, int j) {
        return i>=0&&i<m&&j>=0&&j<n;
    }
    int dfs(int i, int j) {
        if(!valid(i, j) || !grid[i][j] || vis[i][j]) return 0;
        vis[i][j] = true;
        int sum = 0;
        for(auto& dir: dirs) {
            sum += dfs(i + dir.first, j + dir.second);
        }
        return 1 + sum;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        int ans = 0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j] && !vis[i][j]) {
                    ans = max(ans, dfs(i, j));
                }
            }
        }
        return ans;
    }
};