class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        const int n = s.size();
        for(int i=0;i<n;++i) {
            if(s[i] == ' ') {
                ans += s[i];
                continue;
            } else {
                string word = "";
                while(i<n && s[i] != ' ') {
                    word += s[i++];
                }
                --i;
                reverse(word.begin(), word.end());
                ans += word;
            }
        }
        return ans;
    }
};