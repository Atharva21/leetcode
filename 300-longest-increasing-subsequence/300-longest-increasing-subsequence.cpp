class Solution {
private:
    int dp[2505][2505];
    vector<int> v;
    int n;
    int dfs(int i=0, int last=-1) {
        if(i >= n) return 0;
        if(dp[i][last+1] != -1) return dp[i][last+1];
        int notChoose = dfs(i+1, last);
        int choose = 0;
        if(last == -1 || v[i] > v[last]) {
            choose = 1 + dfs(i+1, i);
        }        
        return dp[i][last+1] = max(notChoose, choose);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        v = nums;
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return dfs();
    }
};