class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        const int n = nums.size();
        if(n < 2) return true;
        bool modified = false;
        for(int i=1;i<n;++i) {
            if(nums[i] < nums[i-1]) {
                // decreasing.
                if(modified) return false;
                modified = true;
                if(i == n-1) {nums[i] = nums[i-1];continue;}
                if(i-1 == 0) {nums[i-1] = -1e5;continue;}
                if(nums[i+1] >= nums[i-1]) {
                    nums[i] = nums[i-1];
                    continue;
                }
                if(nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i];
                    continue;
                }
                return false;
            }
        }
        return true;
    }
};