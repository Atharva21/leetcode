class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int n = nums.size();
        int mid = INT_MIN;
        stack<int> s;
        for(int i=n-1;i>=0;--i) {
            if(nums[i] < mid)
                return true;
            while(!s.empty() && nums[i] > s.top()) {
                mid = s.top();s.pop();
            }
            s.push(nums[i]);
        }
        return false;
    }
};














