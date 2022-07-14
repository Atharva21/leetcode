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
    vector<int> pre, in;
    vector<bool> vis;
    unordered_map<int, int> mp;
    int n;
    TreeNode* dfs(int i, int lo, int hi) {
        if(lo < 0 || hi >= n || hi < lo || i >= n) return NULL;
        if(vis[i]) return dfs(i+1, lo, hi);
        vis[i] = true;
        // cout << pre[i] << ": " << lo << " " << hi << endl;
        auto node = new TreeNode(pre[i]);
        node->left = dfs(i+1, lo, mp[pre[i]]-1);
        node->right = dfs(i+1, mp[pre[i]]+1, hi);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        pre = preorder;
        in = inorder;
        n = in.size();
        vis.resize(n, false);
        for(int i=0;i<n;++i) mp[in[i]] = i;
        return dfs(0, 0, n-1);
    }
};