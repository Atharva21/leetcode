/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto front = q.front();q.pop();
            auto node = front.first;
            if(!node) continue;
            auto level = front.second;
            if(level == ans.size()) {
                ans.push_back({node->val});
            } else {
                ans[level].push_back(node->val);
            }
            for(auto& c: node->children) 
                q.push({c, level+1});
        }
        return ans;
    }
};































