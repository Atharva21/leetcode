class Solution {
public:
    bool wordPattern(string pattern, string s) {
        const int n = s.size();
        unordered_map<char, string> patword;
        unordered_map<string, char> wordpat;
        
        vector<string> words;
        string sub = "";
        for(int i=0;i<n;++i) {
            if(s[i] == ' ') {
                words.push_back(sub);
                sub = "";
                continue;
            }
            sub += s[i];
        }
        words.push_back(sub);
        
        if(words.size() != pattern.size()) return false;
        const int m = words.size();
        for(int i=0;i<m;++i) {
            string word = words[i];
            if(wordpat.find(word) != wordpat.end() ||
              patword.find(pattern[i]) != patword.end()) {
                if(wordpat[word] != pattern[i]) return false;
                if(patword[pattern[i]] != word) return false;
            }
            else {
                wordpat[word] = pattern[i];
                patword[pattern[i]]  = word;
            }
        }
        return true;
    }
};