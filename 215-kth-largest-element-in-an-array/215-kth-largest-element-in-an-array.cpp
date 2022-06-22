class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        const int n = nums.size();
        if(k > n) return -1;
        sort(nums.begin(), nums.end());
        return nums[n-k];
    }
};