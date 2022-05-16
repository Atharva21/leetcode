class Solution {
private:
    vector<pair<int, int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {1, 1},
        {1, -1},
        {-1, 0},
        {-1, 1},
        {-1, -1}
    };
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        const int n = grid.size();
        if(grid[0][0] != 0 || grid[n-1][n-1] != 0) return -1;
        queue<pair<int, int>> q;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j] != 0) {
                    grid[i][j] = -1;
                    continue;
                };
                grid[i][j] = INT_MAX;
            }
        }
        grid[0][0] = 1;
        q.push({0, 0});
        while(!q.empty()) {
            auto front = q.front();q.pop();
            for(auto& dir: dirs) {
                int newx = front.first+dir.first;
                int newy = front.second+dir.second;
                if(newx<0||newx>=n||newy<0||newy>=n) continue;
                if(grid[newx][newy] == -1) continue;
                if(grid[newx][newy] > (grid[front.first][front.second] + 1)) {
                    grid[newx][newy] = grid[front.first][front.second] + 1;
                    q.push({newx, newy});
                }
            }
        }
        return grid[n-1][n-1] == INT_MAX ? -1 : grid[n-1][n-1];
    }
};