class Solution {
public:
    int maxArea(int height, int width, vector<int>& horizontal, vector<int>& vertical) {
        sort(horizontal.begin(), horizontal.end());
        sort(vertical.begin(), vertical.end());
        horizontal.push_back(height);
        vertical.push_back(width);
        const int m = horizontal.size();
        const int n = vertical.size();
        long long maxhor = 0;
        for(int h=0;h<m;++h) {
            long long curh = horizontal[h];
            long long prevh = h-1 < 0 ? 0 : horizontal[h-1];
            maxhor = max(maxhor, curh-prevh);
        }
        long long ans = 0;
        for(int v=0;v<n;++v) {
            long long curv = vertical[v];
            long long prevv = v-1 < 0 ? 0 : vertical[v-1];
            ans = max(ans, (curv-prevv)*maxhor);
        }
        return ans % ((int)1e9+7);
    }
};