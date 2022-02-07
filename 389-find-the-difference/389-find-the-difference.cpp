class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for(auto& c: s) ++mp1[c];
        for(auto& c: t) ++mp2[c];
        for(auto& p: mp2) {
            if(mp1[p.first] < p.second) return p.first;
        }
        return ' ';
    }
};