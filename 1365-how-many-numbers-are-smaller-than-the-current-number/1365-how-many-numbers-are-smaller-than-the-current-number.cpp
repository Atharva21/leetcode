class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        const int n = nums.size();
        vector<pair<int, int>> v;
        for(int i=0;i<n;++i) v.push_back({nums[i], i});
        sort(v.begin(), v.end());
        vector<int> ans(n);
        for(int i=0;i<n;++i) {
            if(i == 0 || v[i-1].first < v[i].first) {   
                v[i].second = ans[v[i].second] = i;
                continue;
            }
            v[i].second = ans[v[i].second] = v[i-1].second;
        }
        return ans;
    }
};