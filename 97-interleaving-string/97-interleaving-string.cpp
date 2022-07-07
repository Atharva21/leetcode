class Solution {
private:
    string a, b, c;
    int m, n, o;
    int dp[102][102];
    bool dfs(int i=0, int j=0, int k=0) {
        if(i == m && j == n) return dp[i][j] = true;
        if(dp[i][j] != -1) return dp[i][j];
        char x = a[i];
        char y = b[j];
        char z = c[k];
        bool ans;
        if(x == z && y == z) {
            // return or of both.
            ans = dfs(i+1, j, k+1) || dfs(i, j+1, k+1);
        } else if(x == z) {
            ans = dfs(i+1, j, k+1);
        } else if(y == z) {
            ans = dfs(i, j+1, k+1);
        } else {
            ans = false;
        }
        return dp[i][j] = ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        a = s1;
        b = s2;
        c = s3;
        m = a.size();
        n = b.size();
        o = c.size();
        if(o != m + n) return false;
        memset(dp, -1, sizeof(dp));
        return dfs();
    }
};