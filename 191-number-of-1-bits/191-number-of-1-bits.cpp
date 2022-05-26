class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        // cout << n << endl;
        while(n) {
            // cout << n << endl;
            ans += (n%2);
            n /= 2;
        }
        return ans;
    }
};