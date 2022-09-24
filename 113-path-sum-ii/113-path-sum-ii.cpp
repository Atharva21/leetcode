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
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int target, vector<int> cur={}) {
        if(!root) return;
        cur.push_back(root->val);
        dfs(root->left, target-root->val, cur);
        dfs(root->right, target-root->val, cur);
        if(!root->left && !root->right && target-root->val==0)
            ans.push_back(cur);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        dfs(root, targetSum);
        return ans;
    }
};