class Solution {
private:
    vector<int> parent, rank;
    int getParent(int i) {
        if(i == parent[i]) return i;
        return parent[i] = getParent(parent[i]);
    }
public:
    int longestConsecutive(vector<int>& nums) {
        const int n = nums.size();
        parent.resize(n, 0);
        rank.resize(n, 1);
        for(int i=0;i<n;++i) parent[i] = i;
        int ans = n == 0 ? 0 : 1;
        unordered_map<int, int> mp;
        for(int i=0;i<n;++i) {
            if(mp.find(nums[i]) == mp.end()) {
                mp[nums[i]] = i;
                if(mp.find(nums[i] - 1) != mp.end()) {
                    int idx = mp[nums[i]-1];
                    int lowerparentidx = getParent(parent[idx]);
                    parent[lowerparentidx] = i;
                    rank[i] += rank[lowerparentidx];
                    ans = max(ans, rank[i]);
                }
                if(mp.find(nums[i] + 1) != mp.end()) {
                    int idx = mp[nums[i]+1];
                    int upperparentidx = getParent(parent[idx]);
                    parent[i] = upperparentidx;
                    rank[upperparentidx] += rank[i];
                    ans = max(ans, rank[upperparentidx]);
                }
            }
        }
        return ans;
    }
};