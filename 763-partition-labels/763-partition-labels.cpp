class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> last;
        const int n = s.size();
        for(int i=0;i<n;++i) {
            last[s[i]] = i;
        }
        vector<int> ans;
        int start = 0, end = last[s[0]];
        int i=0;
        while(i < n) {
            if(i == end) {
                ans.push_back(i-start+1);
                start = i+1;
                end = last[s[start]];
                ++i;
                continue;
            }
            if(last[s[i]] > end) {
                end = last[s[i]];
            }
            ++i;
        }
        return ans;
    }
};