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
    string ans = "";
    void preorder(TreeNode* root) {
        if(!root) return;
        ans += to_string(root->val);
        if(root->left && root->right) {
            ans += '(';
            preorder(root->left);
            ans += ')';
            ans += '(';
            preorder(root->right);
            ans += ')';
            return;
        }
        if(root->left || root->right) {
            if(root->left) {
                ans += '(';
                preorder(root->left);
                ans += ')';
                return;
            }
            ans += "()";
            ans += '(';
            preorder(root->right);
            ans += ')';
            return;
        }
        if(root->left) {
            ans += '(';
            preorder(root->left);
            ans += ')';
        }
        if(root->right) {
            ans += '(';
            preorder(root->right);
            ans += ')';
        }
    }
public:
    string tree2str(TreeNode* root) {
        preorder(root);
        return ans;
    }
};