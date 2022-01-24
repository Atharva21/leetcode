class Solution {
private:
    bool is_capital(char c) {
        return c >= 'A' && c <= 'Z';
    }
public:
    bool detectCapitalUse(string word) {
        const int n = word.size();
        if(is_capital(word[0])) {
            if(n == 1) return true;
            bool caps = is_capital(word[1]);
            for(int i=2;i<n;++i) {
                if(is_capital(word[i]) != caps) return false;
            }
        } else {
            for(auto& c: word) {
                if(is_capital(c)) return false;
            }
        }
        return true;
    }
};