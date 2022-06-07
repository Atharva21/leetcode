class Solution {
public:
    void merge(vector<int>& v1, int m, vector<int>& v2, int n) {
        vector<int> ans(m+n);
        int i=0, j=0, k=0;
        while(i<m&&j<n) {
            if(v1[i] < v2[j]) {
                ans[k++] = v1[i++];
            } else {
                ans[k++] = v2[j++];
            }
        }
        while(i<m) {
            ans[k++] = v1[i++];
        }
        while(j<n) {
            ans[k++] = v2[j++];
        }
        v1 = ans;
    }
};