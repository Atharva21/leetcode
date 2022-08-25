class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp;
        for(auto& c: magazine) ++mp[c];
        for(auto& c: ransomNote) {
            auto& i = mp[c];
            if(!i) return false;
            --i;
        }
        return true;
    }
};