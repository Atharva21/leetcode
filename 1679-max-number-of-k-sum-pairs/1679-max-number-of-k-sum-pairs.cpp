class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        int ans = 0;
        while(l < r) {
            if(nums[l] + nums[r] > k) {
                --r;
            } else if(nums[l] + nums[r] < k) {
                ++l;
            } else {
                ++ans;
                ++l;
                --r;
            }
        }
        return ans;
    }
};