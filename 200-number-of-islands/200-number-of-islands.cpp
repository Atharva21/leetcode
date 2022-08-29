class Solution {
private:
    vector<vector<bool>> vis;
    int m, n;
    const vector<pair<int, int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n) return;
        if(grid[i][j] == '0' || vis[i][j]) return;
        vis[i][j] = true;
        for(auto& dir: dirs) {
            dfs(grid, i+dir.first, j+dir.second);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        
        int islands = 0;
        
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j] == '0' || vis[i][j])
                    continue;
                ++islands;
                dfs(grid, i, j);
            }
        }
        
        return islands;
    }
};