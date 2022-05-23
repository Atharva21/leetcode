class Solution {
private:
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> v;
        for(auto& s: strs) {
            pair<int, int> p = {0, 0};
            for(auto& c: s) {
                if(c == '0') {
                    ++p.first;
                } else {
                    ++p.second;
                }
            }
            v.push_back(p);
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(auto& p: v) {
            int zeros = p.first;
            int ones = p.second;
            for(int i=m;i>=zeros;--i) {
                for(int j=n;j>=ones;--j)
                    dp[i][j] = max(dp[i][j], dp[i-zeros][j-ones]+1);
            }
        }
        return dp[m][n];
    }
};