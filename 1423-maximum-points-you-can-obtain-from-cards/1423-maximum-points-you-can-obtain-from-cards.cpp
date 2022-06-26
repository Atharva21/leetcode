class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        const int n = cards.size();
        vector<int> prefixsum(n+1, 0);
        for(int i=1;i<=n;++i) {
            prefixsum[i] = prefixsum[i-1] + cards[i-1];
        }
        if(k >= n) return prefixsum[n];
        int ans = 0;
        for(int i=n-k;i<=n;++i) {
            int lastdiff = n-i;
            int remaining = k - lastdiff;
            int lastsum = prefixsum[n] - prefixsum[i];
            int firstsum = prefixsum[remaining];
            ans = max(ans, lastsum + firstsum);
        }
        return ans;
    }
};