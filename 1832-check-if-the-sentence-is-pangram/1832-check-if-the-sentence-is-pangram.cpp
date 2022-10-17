class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> vis(26, false);
        for(auto& c: sentence)
            vis[c-'a'] = true;
        for(auto v: vis)
            if(!v)
                return false;
        return true;
    }
};