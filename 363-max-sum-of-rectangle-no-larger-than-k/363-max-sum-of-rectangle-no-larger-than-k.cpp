class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        const int rowSize = matrix.size();
        const int colSize = matrix[0].size();
        
        int result = INT_MIN;
        
        for(int l=0;l<colSize;++l) {
            vector<int> rowSum(rowSize, 0);
            for(int r=l;r<colSize;++r) {
                for(int i=0;i<rowSize;++i)
                    rowSum[i] += matrix[i][r];
                
                set<int> s;
                s.insert(0);
                int cursum = 0;
                for(auto& num: rowSum) {
                    cursum += num;
                    auto it = s.lower_bound(cursum - k);
                    if(it != s.end())
                        result = max(result, cursum-*it);
                    s.insert(cursum);
                }
                
            }
        }
        
        return result;
    }
};















