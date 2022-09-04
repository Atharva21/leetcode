class Solution {
private:
    int m, n, visCount=0, cellCount;
    vector<vector<bool>> vis;
    const vector<pair<int, int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    int dfs(vector<vector<int>>& grid, int i, int j) {
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == -1)
            return 0;
        vis[i][j] = true;
        ++visCount;
        int ways = 0;
        if(grid[i][j] == 2) {
            // end square
            ways = (visCount == cellCount) ? 1 : 0;
            // cout << visCount << " " << ways << endl;
        } else {
            // 0(empty)
            for(auto& dir: dirs) {
                ways += dfs(grid, i+dir.first, j+dir.second);
            }
        }
        vis[i][j] = false;
        --visCount;
        return ways;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.resize(m, vector<bool>(n, false));
        int startX, startY, obstacles=0;
        for(int i=0;i<m;++i)
            for(int j=0;j<n;++j) {
                if(grid[i][j] == 1) {   
                    startX = i;
                    startY = j;
                } else if(grid[i][j] == -1)
                    ++obstacles;
            }
        cellCount = (m*n) - obstacles;
        return dfs(grid, startX, startY);
    }
};


























