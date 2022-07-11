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
    int maxHeightVisible = -1;
    vector<int> ans;
    void dfs(TreeNode* root, int height = 0, bool visible = true) {
        if(!root) return;
        if(visible || height > maxHeightVisible) {
            maxHeightVisible = max(maxHeightVisible, height);
            ans.push_back(root->val);
            dfs(root->right, height+1, true);
            dfs(root->left, height+1, root->right == NULL);
            return;
        }
        dfs(root->right, height+1, false);
        dfs(root->left, height+1, false);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root);
        return ans;
    }
};