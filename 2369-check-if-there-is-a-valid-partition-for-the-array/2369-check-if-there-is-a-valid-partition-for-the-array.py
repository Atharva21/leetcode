class Solution:
    
    def isGood(self, start, end):
        if(end-start == 1):
            return self.nums[start] == self.nums[end]
        return (self.nums[start] == self.nums[start+1] and self.nums[start+1] == self.nums[end]) or (self.nums[start] + 1 == self.nums[start+1] and self.nums[start+1] + 1 == self.nums[end])
    
    def validPartition(self, nums: List[int]) -> bool:
        self.nums = nums
        n = len(self.nums)
        if n < 2:
            return False
        dp = [False for _ in range(n)]
        dp[n-2] = self.isGood(n-2, n-1)
        if n-3 >= 0:
            dp[n-3] = self.isGood(n-3, n-1)
        for i in range(n-4, -1, -1):
            dp[i] = (self.isGood(i, i+1) and dp[i+2]) or (self.isGood(i, i+2) and dp[i+3])
        return dp[0]
        