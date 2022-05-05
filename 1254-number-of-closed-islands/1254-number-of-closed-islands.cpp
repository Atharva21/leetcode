class Solution {
private:
    vector<vector<int>> v;
    int m, n;
    vector<pair<int, int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    bool valid(int i, int j) {
        return i>=0&&i<m&&j>=0&&j<n;
    }
    void dfs(int i, int j) {
        if(!valid(i, j) || v[i][j] != 0) return;
        v[i][j] = -1;
        for(auto& dir: dirs) {
            dfs(i+dir.first, j+dir.second);
        }
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        v = grid;
        m = v.size();
        n = v[0].size();
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if((i==0||j==0||i==m-1||j==n-1) && (v[i][j] == 0)) dfs(i, j);
            }
        }
        int ans=0;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(v[i][j] == 0) {
                    ++ans;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }
};