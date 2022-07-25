class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if(lb == nums.end() || *lb != target) return {-1, -1};
        auto ub = upper_bound(nums.begin(), nums.end(), target);
        return {int(lb-nums.begin()), int(ub-nums.begin())-1};
    }
};