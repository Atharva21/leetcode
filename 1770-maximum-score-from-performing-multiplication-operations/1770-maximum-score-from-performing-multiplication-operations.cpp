class Solution {
private:
    int m, n;
    int dp[1001][1001];
    bool vis[1001][1001];
    int maxScore(vector<int>& nums, vector<int>& multipliers, int start, int end, int operations) {
        if(end < start || operations == m) return 0;
        if(vis[start][operations])
            return dp[start][operations];
        vis[start][operations] = true;
        // cout << start << " " << end << " " << operations << endl;
        return dp[start][operations] = max(
            multipliers[operations]*nums[start] + maxScore(nums, multipliers, start+1, end, operations+1),
            multipliers[operations]*nums[end] + maxScore(nums, multipliers, start, end-1, operations+1)
        );
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        m = multipliers.size();
        n = nums.size();
        return maxScore(nums, multipliers, 0, n-1, 0);
    }
};