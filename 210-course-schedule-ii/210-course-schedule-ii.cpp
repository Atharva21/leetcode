class Solution {
private:
    vector<int> ans;
    vector<bool> gvis;
    unordered_map<int, vector<int>> mp;
    bool dfs(int i, vector<bool> vis) {
        if(vis[i]) return false;
        if(gvis[i]) return true;
        gvis[i] = true;
        
        vis[i] = true;
        for(auto& nbr: mp[i]) {
            if(!dfs(nbr, vis)) {
                return false;
            }
        }
        vis[i] = false;
        ans.push_back(i);
        
        return true;
    }
public:
    Solution() {
        for(int i=0;i<2002;++i) gvis.push_back(false);
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        for(auto& p: pre) {
            mp[p[0]].push_back(p[1]);
        }
        for(int i=0;i<n;++i) {
            if(gvis[i]) continue;
            if(mp[i].size() == 0) {
                // no preqsits.
                gvis[i] = true;
                ans.push_back(i);
            } else {
                if(!dfs(i, vector<bool>(n, false))) {
                    return {};
                }
            }
        }
        return ans;
    }
};