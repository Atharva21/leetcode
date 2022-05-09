class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        const int n = grid.size();
        queue<pair<int, int>> q;
        for(int i=0;i<n;++i) {
            for(int j=0;j<n;++j) {
                if(grid[i][j] == 1)
                    q.push({i, j});
            }
        }
        if(q.size() == n*n) return -1;
        int dist = 0;
        vector<pair<int, int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        while(!q.empty()) {
            ++dist;
            int size = q.size();
            while(size--) {
                auto front = q.front();q.pop();
                int x = front.first;
                int y = front.second;
                for(auto& dir: dirs) {
                    int newx = x + dir.first;
                    int newy = y + dir.second;
                    if(newx<0||newx>=n||newy<0||newy>=n||grid[newx][newy]==1)
                        continue;
                    grid[newx][newy] = 1;
                    q.push({newx, newy});
                }
                
            }
        }
        return dist-1;
    }
};