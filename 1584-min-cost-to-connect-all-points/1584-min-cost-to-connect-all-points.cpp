class Solution {
private:
    vector<int> ranks, parents;
    int getParent(int node) {
        if(parents[node] == node) return node;
        return parents[node] = getParent(parents[node]);
    }
    void makeUnion(int u, int v) {
        u = getParent(u);
        v = getParent(v);
        if(ranks[u] < ranks[v]) {
            parents[u] = v;
            ranks[v]++;
        } else {
            parents[v] = u;
            ranks[u]++;
        }
    }
    struct less_than_key {
        inline bool operator() (const vector<int>& v1, const vector<int>& v2) {
            return (v1[0] < v2[0]);
        }
    };
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int nodes = points.size();
        ranks.resize(nodes+1, 0);
        parents.resize(nodes+1, 0);
        for(int i=1;i<=nodes;++i) parents[i] = i;
        vector<vector<int>> weights;
        for(int i=0;i<nodes;++i) {
            for(int j=i+1;j<nodes;++j) {
                weights.push_back({abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]), i, j});
            }
        }
        sort(weights.begin(), weights.end(), less_than_key());
        int ans = 0;
        for(int i=0;i<weights.size();++i) {
            int u = weights[i][1];
            int v = weights[i][2];
            if(getParent(u) == getParent(v)) continue;
            makeUnion(u, v);
            ans += weights[i][0];
        }
        return ans;
    }
};