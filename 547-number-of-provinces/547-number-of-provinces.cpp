class Solution {
private:
    int ans=0, n;
    vector<bool> vis;
    vector<vector<int>> graph;
    void dfs(int i) {
        if(vis[i]) return;
        vis[i] = true;
        for(int j=0;j<n;++j) {
            if(graph[i][j])
                dfs(j);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& graph) {
        this->graph = graph;
        n = graph.size();
        vis.resize(n, false);
        for(int i=0;i<n;++i) {
            if(vis[i]) continue;
            dfs(i);
            ++ans;
        }
        return ans;
    }
};