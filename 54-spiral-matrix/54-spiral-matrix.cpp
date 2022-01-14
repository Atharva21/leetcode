class Solution {
private:
    vector<int> ans;
    vector<vector<int>> grid;
    int m, n;
    vector<pair<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    bool vis[12][12];
    bool valid(int i, int j) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    void dfs(int i=0, int j=0, int dir=0) {
        vis[i][j] = true;
        ans.push_back(grid[i][j]);
        int nxti = i+dirs[dir].first;
        int nxtj = j+dirs[dir].second;
        if(valid(nxti, nxtj) && !vis[nxti][nxtj]) {
            dfs(nxti, nxtj, dir);
        } else {
            int rhti = i+dirs[(dir+1)%4].first;
            int rhtj = j+dirs[(dir+1)%4].second;
            if(valid(rhti, rhtj) && !vis[rhti][rhtj]) {
                dfs(rhti, rhtj, (dir+1)%4);
            }
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memset(vis, false, sizeof(vis));
        grid = matrix;
        dfs();
        return ans;
    }
};