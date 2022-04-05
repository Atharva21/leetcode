class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        set<pair<int, int>> s;
        for(auto& i: intervals) s.insert({i[0], i[1]});
        vector<vector<int>> ans;
        int last = 0;
        for(auto& i: s) {
            if(ans.empty()) {
                ans.push_back({i.first, i.second});
                continue;
            }
            if(i.first <= ans[last][1]) {
                ans[last][0] = min(i.first, ans[last][0]);
                ans[last][1] = max(i.second, ans[last][1]);
            } else {
                ans.push_back({i.first, i.second});
                ++last;
            }
        }
        return ans;
    }
};