class Solution {
private:
    vector<vector<int>> ans;
    vector<int> vis;
    bool dp[62][11][10];
    void dfs(int n, int k, int i=1) {
        if(n < 0 || k < 0) return;
        if(n == 0 && k == 0) {
            vector<int> cur;
            for(int j=1;j<i;++j)  {
                if(vis[j]) cur.push_back(j);
            }
            ans.push_back(cur);
            return;
        }
        if(i > 9) return;
        // if(dp[n][k][i]) return;
        dfs(n, k, i+1);
        vis[i] = true;
        dfs(n-i, k-1, i+1);
        vis[i] = false;
        // dp[n][k][i] = true;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vis.resize(10, false);
        memset(dp, false, sizeof(dp));
        dfs(n, k);
        return ans;
    }
};