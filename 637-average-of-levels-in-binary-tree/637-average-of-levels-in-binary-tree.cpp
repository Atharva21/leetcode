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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if(!root) return ans;
        vector<int> numNodes;
        vector<long long> sum;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto front = q.front();q.pop();
            auto node = front.first;
            if(!node) continue;
            auto level = front.second;
            if(level == numNodes.size()) {
                sum.push_back(node->val);
                numNodes.push_back(1);
            } else {
                ++numNodes[level];
                sum[level] += node->val;
            }
            q.push({node->left, level+1});
            q.push({node->right, level+1});
        }
        const int n = numNodes.size();
        for(int i=0;i<n;++i) {
            ans.push_back(sum[i]/(double)numNodes[i]);
        }
        return ans;
    }
};





















