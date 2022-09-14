/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private final int[] count = new int[10];
    private int ans = 0;
    
    private void dfs(TreeNode root) {
        if(root == null) return;
        ++count[root.val];
        if(root.left == null && root.right == null) {
            boolean oddCount = false;
            for(int cnt: count) {
                if(cnt % 2 == 1) {
                    if(oddCount) {
                        --count[root.val];
                        return;
                    }
                    oddCount = true;
                }
            }
            ++ans;
        } else {
            dfs(root.left);
            dfs(root.right);
        }
        --count[root.val];
    }
    
    public int pseudoPalindromicPaths (TreeNode root) {
        dfs(root);
        return ans;
    }
    
}