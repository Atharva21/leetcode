class Solution {
private:
    int m, n;
    vector<pair<int, int>> dirs = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
    };
    bool valid(int i, int j) {
        return i>=0&&j>=0&&i<m&&j<n;
    }
    void dfs(vector<vector<int>>& image, int check, int fill, int i, int j) {
        if(!valid(i, j) || image[i][j] != check || image[i][j] == fill) return;
        image[i][j] = fill;
        for(auto& dir: dirs) dfs(image, check, fill, i+dir.first, j+dir.second);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        dfs(image, image[sr][sc], newColor, sr, sc);
        return image;
    }
};