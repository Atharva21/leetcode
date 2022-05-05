class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(mat[i][j] == 0) {dist[i][j]=0;q.push({i, j});}
            }
        }
        while(!q.empty()) {
            auto front = q.front();q.pop();
            for(auto& dir: dirs) {
                int x = dir.first+front.first;
                int y = dir.second+front.second;
                if(x>=0&&x<m&&y>=0&&y<n) {
                    if(dist[x][y] > dist[front.first][front.second]+1) {
                        dist[x][y] = dist[front.first][front.second]+1;
                        q.push({x, y});
                    }
                }
            }
        }
        return dist;
    }
};