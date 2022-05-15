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
    pair<int, int> ans;
    void dfs(TreeNode* root, int level=0) {
        if(!root) return;
        if(level > ans.first) {
            ans.first = level;
            ans.second = root->val;
        } else if(level == ans.first) {
            ans.second += root->val;
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root);
        return ans.second;
    }
};