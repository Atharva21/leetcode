class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        set<pair<int, int>> s;
        const int n = intervals.size();
        vector<int> ans;
        for(int i=0;i<n;++i) {
            s.insert({intervals[i][0], i});
        }
        for(auto& interval: intervals) {
            auto lb = s.lower_bound({interval[1], INT_MIN});
            if(lb == s.end()) {
                ans.push_back(-1);
                continue;
            }
            ans.push_back(lb->second);
        }
        return ans;
    }
};











