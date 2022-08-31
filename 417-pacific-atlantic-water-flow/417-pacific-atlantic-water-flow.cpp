class Solution {
private:
    int m, n;
    const vector<pair<int, int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> atlantic, pacific;
        pacific.resize(m, vector<bool>(n, false));
        atlantic.resize(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, pair<bool, bool>>> q;
        
        if(m == 1 || n == 1) {
            for(int i=0;i<m;++i) {
                for(int j=0;j<n;++j) {
                    q.push({{i, j}, {true, true}});
                }
            }
        } else {
            for(int i=0;i<m;++i) {
                for(int j=0;j<n;++j) {
                    if(i == 0 && j == n-1) {
                        q.push({{i, j}, {true, true}});
                        continue;
                    }
                    if(i == m-1 && j == 0) {
                        q.push({{i, j}, {true, true}});
                        continue;
                    }
                    if(i == 0 || j == 0) {
                        q.push({{i, j}, {true, false}});
                        continue;
                    }
                    if(i == m-1 || j == n-1) {
                        q.push({{i, j}, {false, true}});
                        continue;
                    }
                }
            }
        }
        
        while(!q.empty()) {
            //bfs
            auto front = q.front();q.pop();
            int x = front.first.first;
            int y = front.first.second;
            bool p = front.second.first;
            bool a = front.second.second;
            // cout << x << " " << y << " " << p << " " << a << endl;
            if(p)
                pacific[x][y] = true;
            if(a)
                atlantic[x][y] = true;
            for(auto& dir: dirs) {
                int newx = x + dir.first;
                int newy = y + dir.second;
                if(newx < 0 || newy < 0 || newx >= m || newy >= n) continue;
                if(heights[newx][newy] < heights[x][y]) continue;
                if(pacific[x][y] && atlantic[x][y]) {
                    if(!pacific[newx][newy] || !atlantic[newx][newy])
                        q.push({{newx, newy}, {true, true}});
                } else if(pacific[x][y] || atlantic[x][y]) {
                    if(pacific[x][y]) {
                        if(!pacific[newx][newy]) {
                            q.push({{newx, newy}, {true, false}});
                        }
                    } else {
                        if(!atlantic[newx][newy]) {
                            q.push({{newx, newy}, {false, true}});
                        }
                    }
                }
            }
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(atlantic[i][j] && pacific[i][j])
                    ans.push_back({i, j});
            }   
        }        
        return ans;
    }
};








