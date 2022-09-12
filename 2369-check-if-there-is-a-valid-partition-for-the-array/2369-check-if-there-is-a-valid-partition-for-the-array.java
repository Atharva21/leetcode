class Solution {
    
    private int[] nums;
    private int n;
    private final int[] vis = new int[(int)1e5+2];
    
    private boolean isGood(int start, int end) {
        if(start < 0 || start >= n || end < 0 || end >= n || end < start)
            return false;
        if(end - start < 1 || end - start > 2)
            return false;
        if(end - start == 1)
            return nums[start] == nums[end];
        if(nums[start] == nums[start+1])
            return nums[start] == nums[end];
        return nums[end] - nums[start+1] == nums[start+1] - nums[start] && nums[start+1] - nums[start] == 1;
    }
    
    private boolean dfs(int i) {
        if(i >= n)
            return false;
        if(vis[i] != -1)
            return vis[i] == 1;
        if(n - i < 2) {
            vis[i] = 0;   
            return false;
        }
        if(n - i == 2 || n - i == 3) {
            boolean ans = isGood(i, n-1);
            vis[i] = ans ? 1 : 0;
            return ans;
        }
        boolean ans = (isGood(i, i+1) && dfs(i+2)) || (isGood(i, i+2) && dfs(i+3));
        vis[i] = ans ? 1 : 0;
        return ans;
    }
    
    public boolean validPartition(int[] nums) {
        this.nums = nums;
        n = nums.length;
        if(n < 2)
            return false;
        Arrays.fill(vis, -1);
        // System.out.println(isGood(0, 2));
        return dfs(0);
    }
}