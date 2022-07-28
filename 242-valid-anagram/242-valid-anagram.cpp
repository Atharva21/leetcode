class Solution {
public:
    bool isAnagram(string s, string t) {
        int dp[26];
        memset(dp, 0, sizeof(dp));
        for(auto& c: s) ++dp[c-'a'];
        for(auto& c: t) {
            int idx = c-'a';
            if(!dp[idx]) return false;
            --dp[idx];
        }
        for(int i=0;i<26;++i) {
            if(dp[i]) return false;
        }
        return true;
    }
};