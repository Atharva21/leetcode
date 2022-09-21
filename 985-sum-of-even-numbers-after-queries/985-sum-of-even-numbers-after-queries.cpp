class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> evenSums;
        const int n = nums.size();
        int evenSum = 0;
        for(auto& num: nums)
            if(num%2 == 0)
                evenSum += num;
        for(auto& query: queries) {
            int num = query[0];
            int index = query[1];
            if(nums[index]%2 == 0)
                evenSum -= nums[index];
            nums[index] += num;
            if(nums[index]%2 == 0)
                evenSum += nums[index];
            evenSums.push_back(evenSum);
        }
        return evenSums;
    }
};