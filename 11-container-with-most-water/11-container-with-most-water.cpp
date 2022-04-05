class Solution {
public:
    int maxArea(vector<int>& height) {
        const int n = height.size();
        int l=0,r=n-1;
        int ans = 0;
        while(l < r) {
            int h1 = height[l];
            int h2 = height[r];
            ans = max(ans, (min(h1, h2)*(r-l)));
            if(h1 < h2) ++l;
            else --r;
        }
        return ans;
    }
};