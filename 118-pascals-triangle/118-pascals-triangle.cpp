class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        for(int i=1;i<numRows;++i) {
            vector<int> row;
            for(int j=0;j<=i;++j) {
                if(j == 0) {
                    row.push_back(ans[i-1][j]);
                    continue;
                }
                if(j == i) {
                    row.push_back(ans[i-1][j-1]);
                    continue;
                }
                row.push_back(ans[i-1][j-1] + ans[i-1][j]); 
            }
            ans.push_back(row);
        }
        return ans;
    }
};