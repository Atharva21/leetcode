class Solution {
private:
    vector<vector<int>> ans;
    vector<int> v;
    vector<int> mp;
    int n;
    void dfs(vector<int> cur={}) {
        if(cur.size() == n) {
            ans.push_back(cur);
            return;
        }
        vector<bool> mploc(25, 0);
        for(int i=0;i<n;++i) {
            if(!mp[v[i]+11] || mploc[v[i]+11]) continue;
            mploc[v[i]+11] = true;
            --mp[v[i] + 11];
            cur.push_back(v[i]);
            dfs(cur);
            cur.pop_back();
            ++mp[v[i] + 11];
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        v = nums;
        n = v.size();
        mp.resize(25, 0);
        for(auto& num: v) {
            ++mp[num+11];
        }
        dfs();
        return ans;
    }
};