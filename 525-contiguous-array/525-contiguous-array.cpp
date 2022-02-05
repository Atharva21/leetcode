class Solution {
public:
    int findMaxLength(vector<int>& v) {
        const int n = v.size();
        for(auto& i: v) 
            if(!i) i = -1;
        vector<int> prefix = {0};
        for(auto& i: v) {
            prefix.push_back(prefix.back()+i);
        }
        int ans=0;
        unordered_map<int, int> mp;
        for(int i=0;i<=n;++i) {
            if(mp.find(prefix[i]) != mp.end()) {
                ans = max(ans, i - mp[prefix[i]]);
            } else {
                mp[prefix[i]] = i;
            }
        }
        return ans;
    }
};