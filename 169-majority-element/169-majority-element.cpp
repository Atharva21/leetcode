class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size();
        if(n == 0) return -1;
        const int k = n/2;
        unordered_map<int, int> cnt;
        for(auto i:nums) ++cnt[i];
        for(auto i:cnt) {
            if(i.second > k) return i.first;
        }
        return -1;
    }
};