class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        const int halfSize = n/2;
        
        for(int i=0;i<halfSize;++i) {
            for(int j=i;j<n-i-1;++j) {
                int topX = i, topY = j;
                int rightX = topY, rightY = n-1-topX;
                int bottomX = rightY, bottomY = n-1-rightX;
                int leftX = bottomY, leftY = n-1-bottomX;
                
                // swap all in reverse
                swap(matrix[leftX][leftY], matrix[bottomX][bottomY]);
                swap(matrix[bottomX][bottomY], matrix[rightX][rightY]);
                swap(matrix[rightX][rightY], matrix[topX][topY]);
            }
        }
    }
};