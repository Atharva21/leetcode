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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto node = q.front();q.pop();
            if(!node.first) continue;
            if(ans.size() == node.second) {
                ans.push_back({node.first->val});
            } else {
                ans[node.second].push_back(node.first->val);
            }
            q.push({node.first->left, node.second+1});
            q.push({node.first->right, node.second+1});
        }
        return ans;
    }
};