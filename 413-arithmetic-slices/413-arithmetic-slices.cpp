class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& v) {
        const int n = v.size();
        vector<int> dp(n, 0);
        int ans = 0;
        int start = 0, end;
        while(start + 2 < n) {
            if(start != 0 && dp[start-1] > 1) {
                ans += dp[start-1]-1;
                dp[start] = dp[start-1]-1;
                ++start;
                continue;
            }
            int cur = 0;
            int diff = v[start+1] - v[start];
            if(diff == v[start+2] - v[start+1]) 
                ++cur;
            if(cur == 0) {
                dp[start] = 0;
                ++start;
                continue;
            }
            end = start + 3;
            
            while(end < n && diff == v[end] - v[end++-1]) {
                ++cur;
            }
            dp[start] = cur;
            ans += cur;
            ++start;
        }
        // for(int i=0;i<n;++i) cout << dp[i] << " ";
        return ans;
    }
};