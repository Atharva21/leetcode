class Solution {
private:
    vector<vector<int>> result;
    vector<int> v;
    int n;
    void dfs(int i, int cur, vector<int> subset={}) {
        if(cur < 0) return;
        if(cur == 0) {
            result.push_back(subset);
            return;
        }
        if(i == n) {
            return;
        }
        for(int j=i;j<n;++j) {
            cur -= v[j];
            subset.push_back(v[j]);
            dfs(j, cur, subset);
            cur += v[j];
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        v = candidates;
        n = v.size();
        dfs(0, target);
        return result;
    }
};