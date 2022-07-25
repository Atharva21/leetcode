class Solution {
private:
    int target;
    vector<int> bs(vector<int>& nums, int lo, int hi) {
        // cout << lo << " " << hi << endl;
        if(lo > hi) return {INT_MAX, INT_MIN};
        const int mid = (lo + hi) / 2;
        if(target > nums[mid]) return bs(nums, mid+1, hi);
        else if(target < nums[mid]) return bs(nums, lo, mid-1);
        auto l = bs(nums, lo, mid-1);
        auto r = bs(nums, mid+1, hi);
        // cout << l[0] << " " << l[1] << endl;
        // cout << r[0] << " " << r[1] << endl;
        return {
            min(mid, l[0]),
            max(mid, r[1])
        };
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        const int n = nums.size();
        if(!n) return {-1, -1};
        this->target = target;
        auto ans = bs(nums, 0, n-1);
        if(ans[0] == INT_MAX) ans[0] = -1;
        if(ans[1] == INT_MIN) ans[1] = -1;
        return ans;
    }
};