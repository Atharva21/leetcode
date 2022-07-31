class SegmentNode {
public:
    int val, leftLimit, rightLimit;
    SegmentNode *left, *right;
    SegmentNode(int val, int leftLimit, int rightLimit) {
        this->left = this->right = NULL;
        this->val = val;
        this->leftLimit = leftLimit;
        this->rightLimit = rightLimit;
    }
};

class NumArray {
private:
    SegmentNode* root;
    vector<int> v;
    int n;
    SegmentNode* constructHelper(vector<int>& v, int lo, int hi) {
        if(lo > hi) return NULL;
        if(lo == hi) return new SegmentNode(v[lo], lo, hi);
        const int mid = (lo + hi) / 2;
        auto leftNode = constructHelper(v, lo, mid);
        auto rightNode = constructHelper(v, mid+1, hi);
        auto node = new SegmentNode(leftNode->val + rightNode->val, lo, hi);
        node->left = leftNode;
        node->right = rightNode;
        return node;
    }
    SegmentNode* constructSegmentTree(vector<int>& v) {
        const int n = v.size();
        if(n == 0) return NULL;
        return constructHelper(v, 0, n-1);
    }
    int query(SegmentNode* root, int lo, int hi) {
        if(root->leftLimit == lo && root->rightLimit == hi) return root->val;
        const int mid = (root->leftLimit + root->rightLimit) / 2;
        if(lo > mid) return query(root->right, lo, hi);
        if(hi <= mid) return query(root->left, lo, hi);
        int leftans = query(root->left, lo, mid);
        int rightans = query(root->right, mid+1, hi);
        return leftans + rightans;
    }
    void updateTree(SegmentNode* root, int index, int delta) {
        if(!root) return;
        root->val += delta;
        const int mid = (root->leftLimit + root->rightLimit) / 2;
        if(index > mid) updateTree(root->right, index, delta);
        else updateTree(root->left, index, delta);
    }
public:
    NumArray(vector<int>& nums) {
        this->v = nums;
        this->n = v.size();
        this->root = constructSegmentTree(nums);
    }
    
    void update(int index, int newValue) {
        const int n = v.size();
        if(!root || index < 0 || index >= n) return;
        int delta = newValue - v[index];
        updateTree(root, index, delta);
        v[index] += delta;
    }
    
    int sumRange(int left, int right) {
        return query(root, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */