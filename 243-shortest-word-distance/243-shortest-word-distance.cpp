class Solution {
public:
    int shortestDistance(vector<string>& words, string a, string b) {
        int ans = INT_MAX;
        int lasta = -1, lastb = -1;
        const int n = words.size();
        for(int i=0;i<n;++i) {
            const string word = words[i];
            if(word == a) {
                lasta = i;
                if(lastb == -1) {
                    continue;
                }
                ans = min(ans, lasta-lastb);
            } else if(word == b) {
                lastb = i;
                if(lasta == -1) {
                    continue;
                }
                ans = min(ans, lastb-lasta);
            }
        }
        return ans;
    }
};