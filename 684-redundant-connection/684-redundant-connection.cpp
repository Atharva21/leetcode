class Solution {
private:
    vector<int> parent;
    int findParent(int i) {
        if(parent[i] == i) return i;
        return parent[i] = findParent(parent[i]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(1001);
        for(int i=0;i<=1000;++i) parent[i] = i;
        for(auto& edge: edges) {
            // cout << edge[0] << " " << edge[1] << endl;
            int a = findParent(edge[0]);
            int b = findParent(edge[1]);
            if(a == b) return edge;
            parent[a] = b;
        }
        return {};
    }
};