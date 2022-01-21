class Solution {
private:
    int n;
    vector<vector<int>> adj;
    vector<bool> vis;
    void dfs(int i) {
        if(vis[i]) return;
        vis[i] = true;
        for(int j=0;j<n;++j) {
            if(adj[i][j])
                dfs(j);
        }
    }
public:
    
    Solution() {
        for(int i=0;i<202;++i) vis.push_back(false);
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        adj = isConnected;
        n = adj.size();
        int ans=0;
        for(int i=0;i<n;++i) {
            if(vis[i]) continue;
            // cout << i << " ";
            ++ans;
            dfs(i);
        }
        return ans;
    }
};