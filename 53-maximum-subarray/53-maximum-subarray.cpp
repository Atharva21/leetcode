class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        if(!n) return 0;
        int glob = nums[0], loc = nums[0];
        for(int i=1;i<n;++i) {
            loc = max(loc+nums[i], nums[i]);
            glob = max(glob, loc);
        }
        return glob;
    }
};