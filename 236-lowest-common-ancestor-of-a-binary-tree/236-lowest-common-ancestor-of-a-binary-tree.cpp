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
    TreeNode *p, *q;
    pair<TreeNode*, TreeNode*> lca(TreeNode* root) {
        if(!root) return {NULL, NULL};
        
        auto l = lca(root->left);
        if(l.first && l.second) return l;
        
        auto r = lca(root->right);
        if(r.first && r.second) return r;
        
        if((l.first || l.second) && (r.first || r.second))
            return {root, root};
        
        if(l.first || l.second) {
            if(l.first) {
                if(root == q) return {root, root};
                return l;
            }
            if(root == p) return {root, root};
            return l;
        }
        
        if(r.first || r.second) {
            if(r.first) {
                if(root == q) return {root, root};
                return r;
            }
            if(root == p) return {root, root};
            return r;
        }
        
        if(root == p) return {root, NULL};
        if(root == q) return {NULL, root};
        
        return {NULL, NULL};
        
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return NULL;
        this->p = p;
        this->q = q;
        return lca(root).first;
    }
};