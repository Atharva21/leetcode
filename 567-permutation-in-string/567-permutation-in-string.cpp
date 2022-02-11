class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        const int m = s1.size();
        const int n = s2.size();
        if(m > n) return false;
        vector<int> m1(26, 0);
        for(auto& c: s1) ++m1[c-'a'];
        for(int i=0;i<=(n-m);++i) {
            if(m1[s2[i]-'a'] == 0) continue;
            vector<int> m2(26, 0);
            for(int j=0;j<m;++j) {
                int x = s2[i+j]-'a';
                ++m2[x];
                if(m1[x] < m2[x]) break;
            }
            if(m1 == m2) return true;
        }
        return false;
    }
};