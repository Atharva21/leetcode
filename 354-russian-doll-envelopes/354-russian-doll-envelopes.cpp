class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
             });
        vector<int> dp;
        for(auto& e: envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), e[1]);
            if(it == dp.end()) {
                dp.push_back(e[1]);
                continue;
            }
            *it = e[1];
        }
        return dp.size();
    }
};