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
    pair<TreeNode*, TreeNode*> inorder(TreeNode*& root) {
        if(!root) return {NULL, NULL};
        if(root->left) {
            auto l = inorder(root->left);
            root->left = NULL;
            l.second->right = root;
            if(root->right) {
                auto r = inorder(root->right);
                root->right = r.first;
                return {l.first, r.second};
            } else {
                return {l.first, root};
            }
        } else {
            if(root->right) {
                auto r = inorder(root->right);
                root->right = r.first;
                return {root, r.second};
            } else {
                return {root, root};
            }
        }
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        return inorder(root).first;
    }
};