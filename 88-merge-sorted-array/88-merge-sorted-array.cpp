class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        vector<int> ans;
        int i=0, j=0;
        while(i<m&&j<n) {
            if(v1[i] < v2[j]) {
                ans.push_back(v1[i++]);
            } else {
                ans.push_back(v2[j++]);
            }
        }
        while(i<m) {
            ans.push_back(v1[i++]);
        }
        while(j<n) {
            ans.push_back(v2[j++]);
        }
        v1 = ans;
    }
};