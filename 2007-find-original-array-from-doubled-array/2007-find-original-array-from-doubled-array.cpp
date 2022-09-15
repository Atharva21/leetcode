class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        const int n = changed.size();
        if(!n || n%2)
            return {};
        unordered_map<int, int> cnt;
        for(auto& num: changed) ++cnt[num];
        vector<int> keys;
        for(auto& p: cnt) keys.push_back(p.first);
        sort(keys.begin(), keys.end(), [](int i, int j){return abs(i) < abs(j);});
        vector<int> ans(n/2);
        int i=0;
        for(auto& key: keys) {
            if(cnt[key] > cnt[2*key])
                return {};
            for(int j=0;j<cnt[key];++j) {
                ans[i++] = key;
                --cnt[key*2];
            }
        }
        return ans;
    }
};