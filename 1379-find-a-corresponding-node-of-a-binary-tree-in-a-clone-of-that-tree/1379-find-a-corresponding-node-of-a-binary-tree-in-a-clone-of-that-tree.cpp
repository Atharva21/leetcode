/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* dfs(TreeNode* original, TreeNode* cloned, TreeNode* ref) {
        if(!original) return NULL;
        if(original == ref) return cloned;
        auto leftans = dfs(original->left, cloned->left, ref);
        if(leftans) return leftans;
        return dfs(original->right, cloned->right, ref);        
    }
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(original, cloned, target);
    }
};