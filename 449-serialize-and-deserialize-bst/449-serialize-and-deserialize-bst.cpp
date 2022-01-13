/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void insert(TreeNode* root, int val) {
        if(!root) return;
        if(root -> left == NULL && val < root -> val) {
            root -> left = new TreeNode(val);
            return;
        }
        if(root -> right == NULL && val > root -> val) {
            root -> right = new TreeNode(val);
            return;
        }
        if(val < root -> val) insert(root -> left, val);
        else insert(root -> right, val);
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string ser = "";
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            if(node == NULL) {
                ser += "N ";
                continue;
            }
            ser += (to_string(node -> val) + " ");
            q.push(node -> left);
            q.push(node -> right);
        }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = NULL;
        string cur = "";
        for(auto& c: data) {
            if(c == 'N') {
                cur = "";
                continue;
            } else if(c == ' ') {
                if(cur.size() == 0) continue;
                // cout << cur << endl;
                int val = stoi(cur);
                cur = "";
                if(!root) {
                    root = new TreeNode(val);
                } else {
                    insert(root, val);
                }
            } else {
                cur += c;
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;