class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        unordered_map<string, bool> mp;
        for(auto& word: words) mp[word] = true;
        for(auto& word: words) {
            const int n = word.size();
            for(int i=1;i<n;++i) {mp[word.substr(i)] = false;}
        }
        int ans = 0;
        for(auto& p: mp) {
            if(!p.second) continue;
            ans += (p.first.size()+1);
        }
        return ans;
    }
};