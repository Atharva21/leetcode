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
    int postorder(TreeNode*& root, int sofar=0) {
        if(!root) return 0;
        int cur = root->val;
        int r = postorder(root->right, sofar);
        int l = postorder(root->left, sofar+r+cur);
        root->val += (sofar+r);
        return r+cur+l;
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        postorder(root);
        return root;
    }
};