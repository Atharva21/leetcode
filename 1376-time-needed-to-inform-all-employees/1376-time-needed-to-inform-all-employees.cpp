class Solution {
private:
    unordered_map<int, vector<int>> emp;
    vector<int> time;
    int dfs(int i) {
        int ans = 0;
        for(auto& sub: emp[i]) {
            ans = max(ans, dfs(sub));
        }
        return ans + time[i];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        time = informTime;
        for(int i=0;i<n;++i) emp[manager[i]].push_back(i);
        return dfs(headID);
    }
};