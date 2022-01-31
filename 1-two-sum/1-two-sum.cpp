class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int, int> um;
        for(int i=0;i<nums.size();++i) {
            int n = nums[i];
            if(um.find(target-n) != um.end() && i != um[target-n]) return {i, um[target-n]};
            um[n] = i;
        }
        
        return {};
        
    }
};