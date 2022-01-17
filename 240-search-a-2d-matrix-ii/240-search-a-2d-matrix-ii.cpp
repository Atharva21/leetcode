class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        const int m = grid.size();
        const int n = grid[0].size();
        int i=0, j=n-1;
        while(i < m && j >= 0) {
            // cout << i << " " << j << endl;
            if(grid[i][j] == target) return true;
            if(grid[i][j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return false;
    }
};