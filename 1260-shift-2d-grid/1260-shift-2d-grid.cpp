class Solution {
private:
    pair<int, int> get_indices(int idx, int m, int n) {
        int x = idx/m;
        int y = idx-(m*x)-1;
        return {x, y};
    }
    pair<int, int> get_rev_indices(int idx, int m, int n) {
        int x = idx/m;
        int y = idx-(m*x)-1;
        return {x, y};
    }
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        const int m = grid.size();
        const int n = grid[0].size();
        const int total = m * n;
        k %= total;
        if(k == 0) return grid;
        
        vector<vector<int>> ans(m, vector<int>(n));
        for(int i=0;i<total;++i) {
            int temp=(i+k)%(total);
            ans[temp/n][temp%n]=grid[i/n][i%n];
        }
        return ans;
    }
};