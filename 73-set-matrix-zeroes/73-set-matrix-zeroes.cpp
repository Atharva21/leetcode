class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        
        vector<pair<int, int>> zeros;
        for(int i=0;i<m;++i) {
            for(int j=0;j<n;++j) {
                if(!matrix[i][j]) zeros.push_back({i, j});
            }
        }
        
        vector<bool> rowvis(m, false);
        vector<bool> colvis(n, false);
        const int k = zeros.size();
        for(int i=0;i<k;++i) {
            if(rowvis[zeros[i].first] && colvis[zeros[i].second])
                continue;
            if(!rowvis[zeros[i].first]) {
                rowvis[zeros[i].first] = true;
                for(int j=0;j<n;++j) {
                    matrix[zeros[i].first][j] = 0;
                }
            }
            if(!colvis[zeros[i].second]) {
                colvis[zeros[i].second] = true;
                for(int j=0;j<m;++j) {
                    matrix[j][zeros[i].second] = 0;
                }
            }
        }
        
    }
};