/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()) {
            auto front = q.front();q.pop();
            auto node = front.first;
            auto level = front.second;
            // cout << node->val << " " << level << endl;
            if(node->left)
                q.push({node->left, level+1});
            if(node->right)
                q.push({node->right, level+1});
            if(q.empty() || q.front().second != level) continue;
            node->next = q.front().first;
        }
        return root;
    }
};