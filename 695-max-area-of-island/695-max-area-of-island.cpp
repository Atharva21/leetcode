class Solution {
private:
    int m, n;
    vector<vector<int>> grid;
    bool vis[51][51];
    vector<pair<int, int>> dirs = {
        {-1, 0},
        {1, 0},
        {0, 1},
        {0, -1}
    };
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    int bfs(int i, int j) {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        int area = 0;
        while(!q.empty()) {
            auto pr = q.front();
            // cout << pr.first << " " << pr.second << " # ";
            q.pop();
            ++area;
            for(auto& dir: dirs) {
                int newx = pr.first + dir.first;
                int newy = pr.second + dir.second;
                if(valid(newx, newy) && grid[newx][newy] == 1 && !vis[newx][newy]) {
                    q.push({newx, newy});
                    vis[newx][newy] = true;
                }
            }
        }
        // cout << " = " << area << endl;
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this -> grid = grid;
        m = grid.size();
        n = grid[0].size();
        memset(vis, false, sizeof(vis));
        int ans = 0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j] == 0 || vis[i][j]) continue;
                ans = max(ans, bfs(i, j));
            }
        }
        return ans;
    }
};