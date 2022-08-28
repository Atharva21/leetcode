class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        const int rowSize = mat.size();
        if(!rowSize) return mat;
        const int colSize = mat[0].size();
        if(!colSize) return mat;
        
        int i = rowSize - 1, j = 0;
        
        while(i > 0 || j < colSize) {
            
            vector<int> diagonal;
            int x = i, y = j;
            while(x < rowSize && y < colSize) {
                diagonal.push_back(mat[x++][y++]);
            }
            sort(diagonal.begin(), diagonal.end());
            x = i, y = j;
            int k = 0;
            while(x < rowSize && y < colSize) {
                mat[x++][y++] = diagonal[k++];
            }
            
            if(i > 0)
                --i;
            else
                ++j;
        }
        
        return mat;
    }
};