class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        const int m = grid.size();
        const int n = grid[0].size();
        int i=m-1,j=0;
        while(i>=0&&j<n) {
            if(grid[i][j] == target) return true;
            if(target < grid[i][j]) {
                // go up.
                --i;
            } else {
                // go right.
                ++j;
            }
        }
        return false;
    }
};