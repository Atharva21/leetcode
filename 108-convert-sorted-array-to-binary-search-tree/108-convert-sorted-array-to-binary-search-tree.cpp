/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    TreeNode* createTree(vector<int> nums, int low, int high) {
        if(low > high) return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node -> left = createTree(nums, low, mid-1);
        node -> right = createTree(nums, mid+1, high);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int n = nums.size();
        return createTree(nums, 0, n-1);
    }
};
















