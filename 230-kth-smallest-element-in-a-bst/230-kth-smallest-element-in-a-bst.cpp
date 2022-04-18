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
    int viscount=0,k,ans=-1;
    void dfs(TreeNode* root) {
        if(!root) return;
        dfs(root->left);
        ++viscount;
        if(viscount == k) {ans=root->val;return;}
        dfs(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k=k;
        dfs(root);
        return ans;
    }
};