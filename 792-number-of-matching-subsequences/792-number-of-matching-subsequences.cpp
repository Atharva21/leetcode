class Solution {
private:
    int n,m;
    string s, word;
    bool issub(int i=0, int j=0) {
        if(i == n) return j == m;
        if(j == m) return true;
        if(s[i] == word[j]) {
            return issub(i+1, j+1);
        }
        return issub(i+1, j);
    }
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        n = s.size();
        this->s = s;
        int ans = 0;
        unordered_map<string, int> mp;
        for(auto& word: words) {
            if(mp.find(word) != mp.end()) {
                ans += mp[word];
                continue;
            }
            this->word = word;
            m = word.size();
            int sub = issub();
            mp[word] = sub;
            ans += sub;
        }
        return ans;
    }
};