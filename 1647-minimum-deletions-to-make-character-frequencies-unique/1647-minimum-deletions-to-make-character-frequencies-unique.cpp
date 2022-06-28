class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> cmp;
        unordered_map<int, int> fmp;
        for(auto& c: s) ++cmp[c];
        for(auto& p: cmp) ++fmp[p.second];
        int ans = 0;
        for(auto& p: cmp) {
            if(fmp[p.second] == 1) continue;
            // more than 1 char has this same freq.
            --fmp[p.second];
            int k = p.second;
            while(k > 0 && fmp[k]) --k;
            if(!k) {
                ans += p.second;
            } else {
                ++fmp[k];
                ans += p.second - k;
            }
        }
        return ans;
    }
};