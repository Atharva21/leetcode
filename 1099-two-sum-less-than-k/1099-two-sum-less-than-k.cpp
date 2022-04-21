class Solution {
public:
    int twoSumLessThanK(vector<int>& v, int k) {
        const int n = v.size();
        sort(v.begin(), v.end());
        int i=0, j=n-1;
        int ans = -1;
        while(i < j) {
            int sum = v[i]+v[j];
            if(sum >= k) {--j;continue;}
            ++i;
            ans = max(ans, sum);
        }
        return ans;
    }
};