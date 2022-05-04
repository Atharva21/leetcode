class Solution {
public:
    int maxOperations(vector<int>& nums, int sum) {
        unordered_map<int, int> mp;
        int ans=0;
        for(auto& n: nums) {
            if(mp[sum-n]) {
                ++ans;
                --mp[sum-n];
                continue;
            }
            ++mp[n];
        }
        return ans;
    }
};