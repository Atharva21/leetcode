class Solution {
private:
    vector<vector<int>> nums;
    int n, ans=0;
    vector<unordered_map<int, int>> dp;
    int helper(int cur=0, int i=0) {
        if(i == 4)
            return cur == 0;
        if(dp[i][cur] != 0) return dp[i][cur]-1;
        int ways=0;
        for(int j=0;j<n;++j) {
            ways += helper(cur+nums[i][j], i+1);
        }
        dp[i][cur] = ways+1;
        return ways;
    }
public:
    Solution() {
        for(int i=0;i<4;++i) {
            unordered_map<int, int> mp;
            dp.push_back(mp);
        }
    }
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        n = nums1.size();
        if(!n) return 0;
        nums.push_back(nums1);
        nums.push_back(nums2);
        nums.push_back(nums3);
        nums.push_back(nums4);
        return helper();
    }
};