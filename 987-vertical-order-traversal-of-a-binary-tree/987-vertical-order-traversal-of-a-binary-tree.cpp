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
// in order to construct the ans we need:
// 1) the range of columns
// 2) in each column, node vals sorted according to asc of rows
// 3) if the row is same and the column is same, the sorted by asc of node values.
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        int minCol = INT_MAX, maxCol = INT_MIN;
        unordered_map<int, vector<pair<int, priority_queue<int>>>> store;
        while(!q.empty()) {
            auto front = q.front();q.pop();
            auto node = front.first;
            if(!node) continue;
            auto row = front.second.first;
            auto col = front.second.second;
            minCol = min(minCol, col);
            maxCol = max(maxCol, col);
            
            if(store.find(col) == store.end()) {
                vector<pair<int, priority_queue<int>>> v;
                store[col] = v;
            }
            auto& rowStore = store[col];
            if(!rowStore.size() || rowStore.back().first != row) {
                pair<int, priority_queue<int>> rowVal;
                priority_queue<int> pq;
                pq.push(-node->val);
                rowVal = {row, pq};
                rowStore.push_back(rowVal);
            } else {
                rowStore.back().second.push(-node->val);
            }
            
            q.push({node->left, {row+1, col-1}});
            q.push({node->right, {row+1, col+1}});
        }
        for(int i=minCol;i<=maxCol;++i) {
            auto& rowStore = store[i];
            vector<int> rowans;
            for(auto& e: rowStore) {
                auto& pq = e.second;
                while(!pq.empty()) {
                    rowans.push_back(-pq.top());
                    pq.pop();
                }
            }
            ans.push_back(rowans);
        }
        return ans;
    }
};
















