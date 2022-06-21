class Solution {
    // TLE Solution.
// private:
//     int n;
//     vector<int> heights;
//     unordered_map<string, int> dp;
//     int dfs(int i, int bricks, int ladders) {
//         if(i == n-1) return n-1;
//         string str = to_string(i) + "#" + to_string(bricks) + "#" + to_string(ladders);
//         if(dp.find(str) != dp.end()) return dp[str];
//         if(heights[i+1] <= heights[i]) return dp[str] = dfs(i+1, bricks, ladders);
//         int brickans = INT_MIN, ladderans = INT_MIN;
//         if(bricks >= (heights[i+1]-heights[i])) {
//             brickans = dfs(i+1, bricks-(heights[i+1]-heights[i]), ladders);
//         }
//         if(ladders) {
//             ladderans = dfs(i+1, bricks, ladders-1);
//         }
//         int ans = max(brickans, ladderans);
//         return dp[str] = ans == INT_MIN ? i : ans;
//     }
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
//         this->heights = heights;
//         n = heights.size();
//         return dfs(0, bricks, ladders);
//     }
public:
    int furthestBuilding(vector<int>& h, int bricks, int ladders) {
        const int n = h.size();
        priority_queue<int> q;
        for(int i=0;i+1<n;++i) {
            int d = h[i+1]-h[i];
            if(d > 0)
                q.push(-d);
            if(q.size() > ladders) {
                bricks += q.top();
                q.pop();
            }
            if(bricks < 0)
                return i;
        }
        return n-1;
    }
};