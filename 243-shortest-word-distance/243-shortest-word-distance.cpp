class Solution {
public:
    int shortestDistance(vector<string>& words, string a, string b) {
        int ans = INT_MAX;
        int lasta = -1, lastb = -1;
        const int n = words.size();
        for(int i=0;i<n;++i) {
            const string word = words[i];
            if(word != a && word != b) continue;
            int *updateIndex, *compareIndex;
            if(word == a) {
                updateIndex = &lasta;
                compareIndex = &lastb;
            } else {
                updateIndex = &lastb;
                compareIndex = &lasta;
            }
            *updateIndex = i;
            if(*compareIndex == -1) {
                continue;
            }
            ans = min(ans, *updateIndex-*compareIndex);
        }
        return ans;
    }
};