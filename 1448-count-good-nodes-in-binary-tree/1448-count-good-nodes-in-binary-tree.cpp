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
    int ans = 0;
    void dfs(TreeNode* root, int maxsofar = INT_MIN) {
        if(!root) return;
        if(root->val >= maxsofar) {
            maxsofar = root->val;
            ++ans;
        }
        dfs(root->left, maxsofar);
        dfs(root->right, maxsofar);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root);
        return ans;
    }
};