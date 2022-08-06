class Solution {
private:
    vector<int> v;
    int n;
    int dp[1001];
    int ways(int sum) {
        if(sum < 0) return 0;
        if(dp[sum] != -1) return dp[sum];
        if(sum == 0) return dp[sum] = 1;
        int ans = 0;
        for(int i=0;i<n;++i) {
            ans += ways(sum-v[i]);
        }
        return dp[sum] = ans;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        v = nums;
        n = v.size();
        memset(dp, -1, sizeof(dp));
        return ways(target);
    }
};