class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        const int m = mat.size();
        const int n = mat[0].size();
        vector<bool> vis(m, false);
        for(int col=0;col<n;++col) {
            for(int row=0;row<m;++row) {
                if(vis[row] || mat[row][col]) continue;
                ans.push_back(row);
                vis[row] = true;
                if(k == ans.size()) return ans;
            }
        }
        // TODO just go through the vis instead and whatever is false, push in ans.
        for(int col=0;col<n;++col) {
            for(int row=0;row<m;++row) {
                if(vis[row]) continue;
                ans.push_back(row);
                vis[row] = true;
                if(k == ans.size()) return ans;
            }
        }
        return ans;
    }
};