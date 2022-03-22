class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = "";
        while(n) {
            if(k > 26) {
                int delta = k - 26;
                if(delta < n-1) {
                    int remaining = (n-1) - delta;
                    ans += ('z' - remaining);
                    k -= (26-remaining);
                } else {
                    ans += 'z';
                    k -= 26;
                }
            } else {
                int letter = k - (n-1);
                ans += ('a' + letter - 1);
                k -= letter;
            }
            --n;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};