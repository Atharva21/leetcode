class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        const int n = nums.size();
        int ans = 0, left = 0, right = 0;
        int flips = 0;
        while(left < n && right < n) {
            // cout << "~~~~" << left << " ~~ " << right << endl;
            if(nums[right]) {
                ans = max(ans, right-left+1);
                // cout << ans << "# " << left << " " << right << endl;
                ++right;
            } else {
                if(flips < k) {
                    // flip and go ahead.
                    ++flips;
                    ans = max(ans, right-left+1);
                    // cout << ans << "## " << left << " " << right << endl;
                    ++right;
                } else {
                    // shrink.
                    if(!nums[left] && flips) {
                        --flips;
                    }
                    if(left == right) {
                        ++left;
                        ++right;
                    } else {
                        ++left;
                    }
                }
            }
        }
        return ans;
    }
};