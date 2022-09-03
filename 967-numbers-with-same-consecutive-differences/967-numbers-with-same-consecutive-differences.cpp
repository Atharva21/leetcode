class Solution {
private:
    vector<int> ans;
    int diff;
    // unordered_map<int, bool> vis[10];
    void permute(int last, int cur, int pos) {
        // if(vis[pos+1][cur]) return;
        // vis[pos+1][cur] = true;
        if(last < 0 || last > 9) return;
        if(pos < 0) {
            ans.push_back(cur);
            return;
        }
        permute(last+diff, cur+((last+diff)*pow(10, pos)), pos-1);
        if(diff > 0)
            permute(last-diff, cur+((last-diff)*pow(10, pos)), pos-1);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        diff = k;
        for(int i=1;i<10;++i) {
            permute(i, i*pow(10, n-1), n-2);
        }
        return ans;
    }
};