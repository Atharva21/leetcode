class Solution {
private:
    unordered_map<int, bool> cycles, safes;
    vector<bool> vis;
    vector<vector<int>> edges;
    bool dfs(int i) {
        if(safes[i]) return true;
        if(cycles[i]) return false;
        if(vis[i]) {
            cycles[i] = true;
            return false;
        }
        vis[i] = true;
        for(auto& nbr: edges[i]) {
            if(!dfs(nbr)) {
                cycles[i] = true;
                return false;
            }
        }
        return safes[i] = true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        edges = graph;
        const int n = graph.size();
        vector<int> ans;
        for(int i=0;i<n;++i) {
            if(cycles[i]) continue;
            if(safes[i]) {
                ans.push_back(i);
                continue;
            }
            vis.resize(n, false);
            if(dfs(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};