class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        int mini = INT_MAX, maxi = INT_MIN;
        for(int i=0;i+1<n;++i) {
            if(nums[i] > nums[i+1]) {
                mini = min(mini, nums[i+1]);
                maxi = max(maxi, nums[i]);
            }
        }
        // for(int i=n-1;i-1>=0;--i) {
        //     if(nums[i] < nums[i-1]) {
        //         maxi = max(maxi, nums[i-1]);
        //     }
        // }
        int l, r;
        for(l=0;l<n;++l) {
            if(mini < nums[l]) break;
        }
        for(r=n-1;r>=0;--r) {
            if(maxi > nums[r]) break;
        }
        return r-l > 0 ? r-l+1 : 0;
    }
};