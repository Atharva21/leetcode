class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0;
        const int m = accounts.size();
        if(m == 0) return 0;
        const int n = accounts[0].size();
        for(int i=0;i<m;++i) {
            int sum = 0;
            for(int j=0;j<n;++j) {
                sum += accounts[i][j];
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};