class Solution {
private:
    int n, sum;
    vector<int> v;
    unordered_map<int, int> mp[21];
    int dfs(int i=0, int cur=0) {
        if(i == n) return cur == sum;
        if(mp[i].find(cur) != mp[i].end()) return mp[i][cur];
        return mp[i][cur] = dfs(i+1, cur-v[i]) + dfs(i+1, cur+v[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        v = nums;
        n = v.size();
        sum = target;
        return dfs();
    }
};