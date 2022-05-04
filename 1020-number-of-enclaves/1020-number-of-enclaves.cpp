class Solution {
private:
    vector<vector<int>> v;
    int m, n;
    bool valid(int i, int j) {
        return i>=0&&i<m&&j>=0&&j<n;
    }
    vector<pair<int, int>> dirs = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };
    void dfs(int i, int j) {
        if(!valid(i, j) || v[i][j] != 1) return;
        v[i][j] = 2;
        for(auto& dir: dirs) {
            dfs(i+dir.first, j+dir.second);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        v = grid;
        m = grid.size();
        n = v[0].size();
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if((i==0||i==m-1||j==0||j==n-1) && v[i][j] == 1) {
                    dfs(i, j);
                }
            }
        }
        int ans=0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(v[i][j] == 1)
                    ++ans;
            }
        }
        return ans;
    }
};