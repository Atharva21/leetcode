class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] ans = {-1, -1};
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i=0;i<nums.length;i++) {
            if(map.get(nums[i]) != null) {
                ans[0] = map.get(nums[i]);
                ans[1] = i;
                break;
            }
            map.put(target-nums[i], i);
        }
        return ans;
    }
}