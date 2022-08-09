class Solution {
private:
    int find(vector<int>& nums, int lo, int hi) {
        if(lo == hi) return lo;
        if(nums[lo] < nums[hi]) return lo; // alrdy sorted
        const int mid = (lo + hi) / 2;
        if(nums[mid] < nums[lo]) return find(nums, lo, mid);
        return find(nums, mid+1, hi);
    }
public:
    int findMin(vector<int>& nums) {
        const int n = nums.size();
        return nums[find(nums, 0, n-1)];
    }
};