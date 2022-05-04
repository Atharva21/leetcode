class Solution {
private:
    vector<int> parent, rank;
    int findParent(int i) {
        return parent[i] == i ? i : parent[i] = findParent(parent[i]);
    }
    void makeUnion(int i, int j) {
        i = findParent(i);
        j = findParent(j);
        if(i == j) return;
        if(rank[i] < rank[j]) {
            ++rank[j];
            parent[i] = j;
        } else {
            ++rank[i];
            parent[j] = i;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        rank.resize(n, 0);
        for(int i=0;i<n;++i) parent.push_back(i);
        int cables = 0;
        for(auto& con: connections) {
            if(findParent(con[0]) == findParent(con[1])) {
                //already connected save the cable.
                ++cables;
                continue;
            }
            makeUnion(con[0], con[1]);
        }
        unordered_set<int> uniques;
        for(int i=0;i<n;++i) {
            uniques.insert(findParent(parent[i]));
        }
        return uniques.size() - 1 > cables ? -1 : uniques.size() - 1;
    }
};