class Solution {
public:
    bool backspaceCompare(string s, string t) {
        const int n = s.size();
        const int m = t.size();
        int skip1=0, skip2 = 0;
        int i = n-1, j = m-1;
        while(i >= 0 && j >= 0) {
            if(s[i] == '#') {
                skip1++;
                --i;
                continue;
            }
            if(t[j] == '#') {
                skip2++;
                --j;
                continue;
            }
            if(skip1 > 0) {
                --i;
                --skip1;
                continue;
            }
            if(skip2 > 0) {
                --j;
                --skip2;
                continue;
            }
            // cout << s[i] << " " << t[j] << endl;
            if(s[i--] != t[j--]) return false;
        }
        while(i >= 0) {
            if(s[i] == '#') {
                skip1++;
            } else {
                if(skip1 == 0) return false;
                --skip1;
            }
            --i;
        }
        while(j >= 0) {
            if(t[j] == '#') {
                skip2++;
            } else {
                if(skip2 == 0) return false;
                --skip2;
            }
            --j;
        }
        return true;
    }
};