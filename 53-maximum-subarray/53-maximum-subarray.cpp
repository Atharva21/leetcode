class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        int ans = nums[0], sofar = nums[0];
        for(int i=1;i<n;++i) {
            sofar = max(sofar+nums[i], nums[i]);
            ans = max(ans, sofar);
        }
        return ans;
    }
};