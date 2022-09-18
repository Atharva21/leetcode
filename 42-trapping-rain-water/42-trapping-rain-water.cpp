class Solution {
public:
    int trap(vector<int>& heights) {
        const int n = heights.size();
        if(!n) return 0;
        vector<int> left_max(n), right_max(n);
        left_max[0] = heights[0];
        right_max[n-1] = heights[n-1];
        for(int i=1;i<n;++i)
            left_max[i] = max(left_max[i-1], heights[i]);
        for(int i=n-2;i>=0;--i)
            right_max[i] = max(right_max[i+1], heights[i]);
        int ans = 0;
        for(int i=0;i<n;++i)
            ans += min(left_max[i], right_max[i]) - heights[i];
        return ans;
    }
};