class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        if(n == 0) return {};
        int lo=0, hi=n-1;
        while(lo<=hi) {
            int sum = numbers[lo] + numbers[hi];
            if(sum == target) {
                return {lo+1, hi+1};
            }
            if(sum > target) {
                --hi;
                continue;
            } else {
                ++lo;
                continue;
            }
        }
        return {};
    }
};