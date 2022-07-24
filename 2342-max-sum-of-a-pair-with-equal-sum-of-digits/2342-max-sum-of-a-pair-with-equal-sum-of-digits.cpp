class Solution {
private:
    int getsum(int n) {
        int sum = 0;
        while(n) {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        const int n = nums.size();
        int ans = -1;
        unordered_map<int, pair<int, int>> mp;
        for(auto& num: nums) {
            int sum = getsum(num);
            if(mp.find(sum) == mp.end()) {
                mp[sum] = {num, 0};
                continue;
            }
            auto p = mp[sum];
            if(p.first + p.second < num + max(p.first, p.second)) {
                ans = max(ans, num + max(p.first, p.second));
                mp[sum] = {num, max(p.first, p.second)};
            }
        }
        return ans;
    }
};