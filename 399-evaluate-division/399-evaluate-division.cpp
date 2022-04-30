class Solution {
private:
    unordered_map<string, unordered_map<string, double>> g;
    double ans;
    unordered_map<string, bool> vis;
    bool dfs(string start, string end, double cur=1) {
        if(start == end) {
            ans = cur;
            return true;
        }
        if(vis[start]) return false;
        vis[start] = true;
        for(auto nbr: g[start]) {
            if(dfs(nbr.first, end, cur*nbr.second)) return true;
        }
        vis[start] = false;
        return false;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        const int n = equations.size();
        for(int i=0;i<n;++i) {
            auto div = values[i];
            auto a = equations[i][0];
            auto b = equations[i][1];
            g[a][b] = div;
            g[b][a]= 1/div;
        }
        vector<double> finalans;
        for(auto query: queries) {
            vis.clear();
            auto a = query[0];
            auto b = query[1];
            if(g[a].size() == 0 || g[b].size() == 0) {
                finalans.push_back(-1);
            }
            else if(dfs(a, b))  {
                finalans.push_back(ans);
            } else {
                finalans.push_back(-1);
            }
        }
        return finalans;
    }
};