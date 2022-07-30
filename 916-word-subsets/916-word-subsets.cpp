class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> maxb(26, 0);
        for(auto& b: words2) {
            vector<int> lb(26, 0);
            for(auto& c: b) ++lb[c-'a'];
            for(int i=0;i<26;++i) maxb[i] = max(maxb[i], lb[i]);
        }
        for(auto& a: words1) {
            vector<int> la(26, 0);
            for(auto& c: a) ++la[c-'a'];
            bool universal = true;
            for(int i=0;i<26;++i) 
                if(la[i] < maxb[i]) {
                    universal=false;
                    break;
                }
            if(universal)
                ans.push_back(a);
        }
        return ans;
    }
};