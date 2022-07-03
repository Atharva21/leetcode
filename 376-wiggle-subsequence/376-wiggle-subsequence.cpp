class Solution {
private:
    vector<int> v;
    int n;
    int dp[1002][1003][2];
    int dfs(bool greater, int i=0, int last=-1) {
        if(i >= n) return 0;
        if(dp[i][last+1][greater] != -1) return dp[i][last+1][greater];
        int notChoose = dfs(greater, i+1, last);
        int choose = INT_MIN;
        if(last == -1 || ((greater && v[i] > v[last]) || !greater && v[i] < v[last])) {
            choose = 1 + dfs(!greater, i+1, i);
        }
        return dp[i][last+1][greater] = max(choose, notChoose);
        // return max(choose, notChoose);
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        v = nums;
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return max(dfs(true), dfs(false));
    }
};