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
    TreeNode* getNode(vector<int>& v, int lo, int hi) {
        if(lo > hi) return NULL;
        const int mid = (lo + hi) / 2;
        auto node = new TreeNode(v[mid]);
        node->left = getNode(v, lo, mid-1);
        node->right = getNode(v, mid+1, hi);
        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        const int n = nums.size();
        if(!n) return NULL;
        return getNode(nums, 0, n-1);
    }
};