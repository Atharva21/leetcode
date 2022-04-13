class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        vector<pair<int, int>> dirs = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0},
        };
        int dir = 0;
        int cur = 1;
        int x = 0;
        int y = 0;
        while(true) {
            ans[x][y] = cur++;
            int nxtx = x+dirs[dir].first;
            int nxty = y+dirs[dir].second;
            if(nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < n && ans[nxtx][nxty] == 0) {
                x = nxtx;
                y = nxty;
            } else {
                // next is either out of bounds or visited
                dir = (dir+1)%4;
                nxtx = x+dirs[dir].first;
                nxty = y+dirs[dir].second;
                if(nxtx >= 0 && nxtx < n && nxty >= 0 && nxty < n && ans[nxtx][nxty] == 0) {
                    x = nxtx;
                    y = nxty;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};