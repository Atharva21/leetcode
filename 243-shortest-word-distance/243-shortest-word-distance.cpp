class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        unordered_map<string, vector<int>> mp;
        int x = 0;
        for(auto& word: wordsDict) mp[word].push_back(x++);
        auto v1 = mp[word1];
        auto v2 = mp[word2];
        int ans = INT_MAX;
        int i=0,j=0;
        int m = v1.size(),n=v2.size();
        while(i<m&&j<n) {
            ans = min(ans, abs(v1[i]-v2[j]));
            if(v1[i] < v2[j]) ++i;
            else ++j;
        }
        return ans;
    }
};