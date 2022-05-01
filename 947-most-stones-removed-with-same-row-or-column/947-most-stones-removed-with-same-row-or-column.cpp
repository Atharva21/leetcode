class Solution {
private:
    vector<int> parent;
    unordered_map<int, vector<int>> xs, ys;
    int findParent(int i) {
        if(i == parent[i])
            return i;
        return parent[i] = findParent(parent[i]);
    }
    void makeUnion(int i, int j) {
        i = findParent(i);
        j = findParent(j);
        parent[i] = j;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        const int n = stones.size();
        for(int i=0;i<n;++i) parent.push_back(i);
        for(int id=0;id<n;++id) {
            xs[stones[id][0]].push_back(id);
            ys[stones[id][1]].push_back(id);
        }
        for(int id=0;id<n;++id) {
            for(int x: xs[stones[id][0]]) makeUnion(id, x);
            for(int y: ys[stones[id][1]]) makeUnion(id, y);
        }
        unordered_set<int> unique;
        for(int i: parent) {
            unique.insert(findParent(parent[i]));
        }
        return n - unique.size();
    }
};