class Solution {
private:
    vector<int> ans;
    vector<int> vis;
    vector<vector<int>> deps;
    bool isprocessed[2002];
    bool dfs(int idx, int visidx) {
        if(vis[idx] == visidx) return false;
        if(vis[idx] >= 0) return true;
        
        //visit
        vis[idx] = visidx;
        
        //recurse through all deps, before returning true;
        auto dependencies = deps[idx];
        for(auto& d: dependencies) {
            if(isprocessed[d]) continue;
            if(!dfs(d, visidx)) return false;
        }
        
        //add to ans
        isprocessed[idx] = true;
        ans.push_back(idx);
        
        return true;
    }
public:
    Solution() {
        for(int i=0;i<2002;++i) {vis.push_back(-1);deps.push_back({});}
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& v: prerequisites) {
            deps[v[0]].push_back(v[1]);
        }
        for(int i=0;i<numCourses;++i) {
            if(vis[i] >= 0) continue;
            // logic.
            memset(isprocessed, false, sizeof(isprocessed));
            if(!dfs(i, i)) return {};
        }
        return ans;
    }
};