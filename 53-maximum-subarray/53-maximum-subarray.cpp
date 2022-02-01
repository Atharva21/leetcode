class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        const int n = nums.size();
        if(!n) return 0;
        int ans = nums[0];
        int cur = nums[0];
        for(int i=1;i<n;++i) {
            int s = cur+nums[i];
            if(s < nums[i])
                cur = nums[i];
            else
                cur = s;
            ans = max(ans, cur);
        }
        return ans;
    }
};