class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k <= 0)
            return false;
        queue<int> q;
        unordered_map<int, bool> vis;
        for(auto& num: nums) {
            if(vis[num])
                return true;
            vis[num] = true;
            if(q.size() == k && !vis.empty()) {
                vis[q.front()] = false;
                q.pop();
            }
            q.push(num);
        }
        return false;
    }
};