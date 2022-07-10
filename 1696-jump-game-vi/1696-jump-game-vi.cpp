class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        const int n = nums.size();
        vector<int> dp(n);
        deque<int> dq = {0};
        dp[0] = nums[0];
        for(int i=1;i<n;++i) {
            if(dq.front() < i-k) dq.pop_front();
            dp[i] = dp[dq.front()] + nums[i];
            while(!dq.empty() && dp[dq.back()] <= dp[i]) dq.pop_back();
            dq.push_back(i);
        }
        return dp[n-1];
    }
};