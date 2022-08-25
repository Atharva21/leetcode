class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto& c: magazine) ++mp[c];
        for(auto& c: ransomNote) {
            auto& i = mp[c]; // a bit faster than writing mp[c], and --mp[c] for 2 lookups
            if(!i) return false;
            --i;
        }
        return true;
    }
};