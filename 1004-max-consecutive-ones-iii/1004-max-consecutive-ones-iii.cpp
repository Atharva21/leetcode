class Solution {
public:
    int longestOnes(vector<int>& v, int k) {
        const int n = v.size();
        if(n == 0) return 0;
        int left=0, right=0, ans=0;
        // sliding window algorithm
        while(left < n) {
            if(k >= 0) {
                ans = max(ans, right-left);
                if(right == n)
                    return ans;
                // if right == n k is only gonna get bigger, and ans shorter.
            }
            if(right == n || (k <= 0 && !v[right])) {   
                k += v[left++] ? 0 : 1;
                continue;
            }
            k -= v[right++] ? 0 : 1;
        }
        return ans;
    }
};













