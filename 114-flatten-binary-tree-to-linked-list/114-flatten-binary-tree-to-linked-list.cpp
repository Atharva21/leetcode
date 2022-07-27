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
    pair<TreeNode*, TreeNode*> makeLinkedList(TreeNode*& root) {
        // the returntype is pair of treenodes so we can return both head and tail of ll.
        if(!root) return {NULL, NULL};
        // cout << root->val << " ";
        auto leftChild = root->left;
        auto rightChild = root->right;
        if(leftChild) {
            root->left = NULL;
            auto leftAns = makeLinkedList(leftChild);
            root->right = leftAns.first;
            leftAns.second->right = rightChild;
            if(rightChild) {
                return {root, makeLinkedList(rightChild).second};
            }
            return {root, leftAns.second};
        }
        if(rightChild) {
            return {root, makeLinkedList(rightChild).second};    
        }
        return {root, root};
    }
public:
    void flatten(TreeNode*& root) {
        makeLinkedList(root);
    }
};