class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto& i: nums) ++mp[i];
        vector<int> ans;
        set<pair<double, int>> asc;
        for(auto& i: mp) {
            asc.insert({(double)1/i.second, i.first});
        }
        int i=0;
        auto itr = asc.begin();
        while(itr != asc.end() && i < k) {
            // cout << itr->second << " ";
            ans.push_back(itr->second);
            itr = next(itr);
            ++i;
        }
        return ans;
    }
};