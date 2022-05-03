class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        const int n = nums.size();
        stack<int> s;
        int l = n, r = 0;
        for(int i=0;i<n;++i) {
            while(!s.empty() && nums[i] < nums[s.top()]) {l=min(l, s.top());s.pop();}
            s.push(i);
        }
        s = stack<int>();
        for(int i=n-1;i>=0;--i) {
            while(!s.empty() && nums[i]>nums[s.top()]) {
                r = max(r, s.top());s.pop();
            }
            s.push(i);
        }
        return r-l>0?r-l+1:0;
    }
};