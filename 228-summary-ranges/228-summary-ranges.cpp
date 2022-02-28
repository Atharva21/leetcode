class Solution {
public:
    vector<string> summaryRanges(vector<int>& v) {
        vector<string> ans;
        int k=0;
        const int n = v.size();
        int i=-1;
        while(++i < n) {
            ans.push_back(to_string(v[i]));
            int j = i;
            while(j+1 < n && v[j] + 1 == v[j+1]) {
                ++j;
            }
            if(j - i >= 1) {
                i = j;
                ans[k] = ans[k] + "->" + to_string(v[i]);
            }
            ++k;
        }
        return ans;
    }
};