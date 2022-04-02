class Solution {
private:
    bool ispal(string s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        const int n = s.size();
        bool deleted = false;
        int i=0, j=n-1;
        while(i < j) {
            if(s[i] != s[j]) {
                if(deleted) return false;
                deleted = true;
                return ispal(s, i+1, j) || ispal(s, i, j-1);
            }
            ++i;--j;
        }
        return true;
    }
};